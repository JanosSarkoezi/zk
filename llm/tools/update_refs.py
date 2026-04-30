import re
import os

def load_mapping(mapping_file):
    mapping = {}
    with open(mapping_file, 'r') as f:
        for line in f:
            if '|' in line:
                key, title = line.strip().split('|', 1)
                mapping[key] = title
    return mapping

def get_search_terms(key, title):
    terms = [title]
    # Remove common prefixes
    prefixes = ["Definition einer ", "Definition eines ", "Definition der ", "Definition von ", "Satz von ", "Satz über die ", "Das ", "Die ", "Der "]
    for p in prefixes:
        if title.lower().startswith(p.lower()):
            terms.append(title[len(p):])
            break
    
    # Core nouns/concepts
    # e.g. "Arithmetische Ableitungsregeln" -> "Ableitungsregeln"
    words = title.split()
    if len(words) > 1:
        terms.append(words[-1])
        if len(words) > 2:
            terms.append(" ".join(words[-2:]))

    # Specific common variations
    if "sigma-Algebra" in title or "sigma_algebra" in key:
        terms.extend(["sigma-Algebra", "sigma-Algebren", "sigma-algebra", "sigma-algebren"])
    
    if "Dynkin-System" in title or "dynkin" in key:
        terms.extend(["Dynkin-System", "Dynkin-Systeme", "Dynkin-Systems", r"Dynkin-System"])
    
    if "Stetigkeit" in title or "stetig" in key:
        terms.extend(["stetig", "Stetigkeit", "stetige"])

    if "Differenzierbar" in title or "ableitung" in key:
        terms.extend(["Ableitung", "differenzierbar", "Ableitungen"])

    if "Konvergenz" in title or "konvergenz" in key:
        terms.extend(["Konvergenz", "konvergiert", "konvergente"])

    if "Integral" in title or "integral" in key:
        terms.extend(["Integral", "Integrale", "integrierbar"])

    # Key-based terms
    key_term = key.replace('_', ' ')
    terms.append(key_term)
    
    # Sort by length descending to match longest first
    return sorted(list(set(terms)), key=len, reverse=True)

def update_file(file_path, mapping):
    with open(file_path, 'r') as f:
        content = f.read()

    # Split YAML header
    parts = content.split('---')
    if len(parts) < 3:
        return
    
    header = parts[1]
    body = '---'.join(parts[2:])

    # Extract refs
    refs_match = re.search(r'refs: \[(.*?)\]', header)
    if not refs_match:
        return
    
    refs = [r.strip() for r in refs_match.group(1).split(',') if r.strip()]
    
    # Identify math blocks to protect them
    protected_blocks = []
    def protect(match):
        # If the match looks like one of our LaTeX search terms, we might NOT want to protect it fully
        # but for simplicity, we protect everything and then handle LaTeX terms separately.
        protected_blocks.append(match.group(0))
        return f"__MATH_BLOCK_{len(protected_blocks)-1}__"

    # Protect display math always
    body = re.sub(r'\$\$.*?\$\$', protect, body, flags=re.DOTALL)
    
    # For inline math, we only protect it if it DOESN'T contain our target LaTeX terms
    # Actually, a simpler way: Protect everything, but allow the replacement logic 
    # to "see" inside the placeholders for specific patterns.
    # Even simpler: Just don't protect simple $...$ if they are exactly our search terms.
    
    body = re.sub(r'\$.*?\$', protect, body)

    replaced_refs = set()

    for ref in refs:
        if ref not in mapping:
            continue
        
        title = mapping[ref]
        terms = get_search_terms(ref, title)
        
        # We need to be careful with word boundaries for LaTeX commands like \sigma
        # Let's use a smarter pattern for terms that might have special chars
        
        for term in terms:
            # Case insensitive match
            # Avoid replacing if already replaced
            if term.startswith('$'): # Special handling for LaTeX terms
                pattern = re.escape(term)
            else:
                pattern = r'\b' + re.escape(term) + r'\b'
            
            # Check if term exists in body (outside links)
            # Use a regex that skips already linked text
            # We'll do it manually to avoid complex regex
            
            def replace_in_body(text, ref, term):
                # This is still a bit simple but better
                # It looks for the term not inside [[...]]
                
                # Split text by [[ and ]]
                segments = re.split(r'(\[\[.*?\]\])', text)
                new_segments = []
                found = False
                for seg in segments:
                    if seg.startswith('[['):
                        new_segments.append(seg)
                    else:
                        # Case insensitive replacement
                        if term.startswith('$'):
                            new_pattern = re.escape(term)
                        else:
                            new_pattern = r'\b' + re.escape(term) + r'\b'
                        
                        def sub_func(match):
                            nonlocal found
                            found = True
                            return f"[[{ref}|{match.group(0)}]]"
                        
                        res = re.sub(new_pattern, sub_func, seg, flags=re.IGNORECASE)
                        new_segments.append(res)
                return "".join(new_segments), found

            body, matched = replace_in_body(body, ref, term)
            if matched:
                replaced_refs.add(ref)
                break # Move to next ref once this one is replaced

    # After trying to replace all terms, check if any refs were missed
    for ref in refs:
        if ref not in replaced_refs:
            # Append [[ref]] at the end of the first paragraph if not replaced
            # or just at the end of body if preferred.
            # User said: "If a key is mentioned but doesn't have a clear descriptive text, use the [[key]] syntax"
            # I'll just append it to the end of the body for now as a "Siehe auch" or similar.
            # Actually, I'll try to find if the key itself was mentioned (maybe in parentheses)
            pass

    # Restore math blocks and handle internal links if any
    for i, block in enumerate(protected_blocks):
        placeholder = f"__MATH_BLOCK_{i}__"
        # Check if we should have linked something inside this block
        # This is for cases like $\sigma$-Algebra
        for ref in refs:
            if ref not in mapping: continue
            terms = get_search_terms(ref, mapping[ref])
            for term in terms:
                if term.startswith('$') and term in block:
                    # Replace inside the block
                    block = block.replace(term, f"[[{ref}|{term}]]")
                    replaced_refs.add(ref)
                    break
        body = body.replace(placeholder, block)

    new_content = '---' + header + '---' + body
    
    with open(file_path, 'w') as f:
        f.write(new_content)

if __name__ == "__main__":
    # Path is relative to the directory where the script is located
    script_dir = os.path.dirname(os.path.abspath(__file__))
    mapping_path = os.path.join(script_dir, 'mapping.txt')
    wiki_dir = os.path.join(script_dir, '../wiki')
    
    mapping = load_mapping(mapping_path)
    # Read files list from wiki directory
    files = [os.path.join(wiki_dir, f) for f in os.listdir(wiki_dir) if f.endswith('.md') and f not in ['index.md', 'log.md']]
    
    for f in files:
        if os.path.exists(f):
            update_file(f, mapping)
