# Git Rebase Check Skript

Um herauszufinden, ob ein Feature-Branch hinter dem `develop`-Branch hinterherhinkt (also neue Commits auf `develop` liegen, die der Feature-Branch noch nicht hat), nutzt man am besten den Git-Befehl `git log`.

Konkret listet `git log develop..SAJ/DEV-5697` alle Commits auf, die auf `develop` liegen, aber **nicht** im Feature-Branch. Wenn diese Liste nicht leer ist, wird ein Rebase benötigt.

Hier ist ein fertiges Bash-Skript, das deine Verzeichnisse und die jeweiligen Branches strukturiert durchläuft und prüft, wo Handlungsbedarf besteht.

---

### Das Bash-Skript (`check_rebase.sh`)

Erstelle eine Datei, z. B. `check_rebase.sh`, und füge folgenden Code ein:

```bash
#!/bin/bash

# Only define the directories here. The script finds the branches automatically!
DIRECTORIES=(
    "$HOME/dev/git/collactive/"
    "$HOME/dev/git/protactive/"
    "$HOME/dev/git/sparactive/"
    "$HOME/dev/git/lblactive/"
    "$HOME/dev/git/trygactive/"
    "$HOME/dev/git/finavactive/"
)

# Colors & Formatting
RED='\033[0;31m'
GREEN='\033[0;32m'
YELLOW='\033[1;33m'
BOLD='\033[1m'
NC='\033[0m' # No Color

echo -e "${BOLD}Starting dynamic Git rebase check against 'develop'...${NC}"
echo "---------------------------------------------------------------------------------"
printf "${BOLD}%-16s %-15s %-20s %s${NC}\n" "STATUS" "REPO" "BRANCH" "INFO"
echo "---------------------------------------------------------------------------------"

for DIR in "${DIRECTORIES[@]}"; do
    # Remove trailing slash if present
    DIR="${DIR%/}"

    if [ ! -d "$DIR" ]; then
        printf "${YELLOW}%-16s${NC} %-15s %-20s %s\n" "[WARNING]" "$(basename "$DIR")" "N/A" "Path does not exist"
        continue
    fi

    (
        cd "$DIR" || exit
        REPO_NAME=$(basename "$DIR")

        # Fetch latest develop state once per repository
        git fetch origin develop &> /dev/null

        # Check if origin/develop exists, otherwise use local develop
        DEVELOP_REF="origin/develop"
        if ! git rev-parse --verify --quiet "$DEVELOP_REF" &>/dev/null; then
            DEVELOP_REF="develop"
        fi

        # Get all local branches except main, master, and develop itself
        LOCAL_BRANCHES=$(git for-each-ref --format='%(refname:short)' refs/heads/ | grep -E -v '^(main|master|develop)$')

        if [ -z "$LOCAL_BRANCHES" ]; then
            printf "${YELLOW}%-16s${NC} %-15s %-20s %s\n" "[INFO]" "$REPO_NAME" "-" "No active feature branches found"
            exit
        fi

        # Loop through all found local branches
        echo "$LOCAL_BRANCHES" | while read -r BRANCH; do
            [ -z "$BRANCH" ] && continue

            # Calculate how many commits develop is ahead of the branch
            BEHIND_COMMITS=$(git log "$BRANCH".."$DEVELOP_REF" --oneline 2>/dev/null | wc -l)

            if [ "$BEHIND_COMMITS" -gt 0 ]; then
                printf "${RED}%-16s${NC} %-15s %-20s (Behind by %d commit(s))\n" "[REBASE NEEDED]" "$REPO_NAME" "$BRANCH" "$BEHIND_COMMITS"
            else
                printf "${GREEN}%-16s${NC} %-15s %-20s up-to-date\n" "[UP-TO-DATE]" "$REPO_NAME" "$BRANCH"
            fi
        done
    )
done

echo "---------------------------------------------------------------------------------"
echo "Check completed."
```

---

### Wichtige Anpassungen im Skript:

1. **Pfad-Korrektur bei `sparactive`:** In deiner Liste war beim Spar-Repo ein GitLab-Link-Überbleibsel (`/-/merge_requests/113`). Das habe ich im Skript auf den reinen Ordnerpfad gekürzt, da Git sonst das Verzeichnis nicht findet.
2. **`git fetch`:** Das Skript führt im Hintergrund ein `git fetch origin develop` aus. Das sorgt dafür, dass der Check auf dem echten, aktuellen Stand des Servers basiert. Wenn du nur rein lokal prüfen willst, kannst du diese Zeile löschen.

### So benutzt du das Skript:

1. Speichere den Code in einer Datei, z. B. `check_git.sh`.
2. Mach das Skript im Terminal ausführbar:
```bash
chmod +x check_git.sh

```


3. Führe es aus:
```bash
./check_git.sh

```

Das Skript gibt dir dann eine farblich sortierte Liste (Grün für "Alles schick", Rot für "Hier musst du rebasen") aus.


