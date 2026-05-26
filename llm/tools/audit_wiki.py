import os
import re

wiki_dir = 'wiki'
index_file = os.path.join(wiki_dir, 'index.md')

files = [f for f in os.listdir(wiki_dir) if f.endswith('.md') and f != 'index.md' and f != 'log.md']
keys = [f[:-3] for f in files]

errors = []

# 1. Check if all files are in index.md
with open(index_file, 'r') as f:
    index_content = f.read()

for key in keys:
    if f'`{key}`' not in index_content and f'| {key} |' not in index_content:
        errors.append(f"Missing in index: {key}")

# 2. Check each file for consistency and broken refs
for filename in files:
    filepath = os.path.join(wiki_dir, filename)
    with open(filepath, 'r') as f:
        content = f.read()
        
    # Check key matches filename
    key_match = re.search(r'^key:\s*(.*)$', content, re.MULTILINE)
    if key_match:
        header_key = key_match.group(1).strip()
        if header_key != filename[:-3]:
            errors.append(f"Key mismatch: {filename} has key {header_key}")
    else:
        errors.append(f"No key found: {filename}")
        
    # Check refs
    refs_match = re.search(r'^refs:\s*\[(.*)\]$', content, re.MULTILINE)
    if refs_match:
        refs = [r.strip() for r in refs_match.group(1).split(',')]
        for ref in refs:
            if not ref: continue
            if ref not in keys:
                # Check if it's a special key or just missing
                errors.append(f"Broken ref in {filename}: {ref}")

    # Check internal links [[key]]
    internal_links = re.findall(r'\[\[(.*?)\]\]', content)
    for link in internal_links:
        link_key = link.split('|')[0]
        if link_key not in keys:
             errors.append(f"Broken internal link in {filename}: [[{link}]]")

for err in errors:
    print(err)

if not errors:
    print("No errors found.")
