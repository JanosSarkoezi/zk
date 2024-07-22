# Gitflow

Gitflow erleichtert das behandeln von Branches unter git.

Typisches forgehen bie Gitflow:

- gup             (git pull --rebase auf develop)
- git flow feature start FEATURE_NAME
- git flow publish

Weiter an nächsten Tag:

- gco develop     (git checkout develop)
- gup             (git pull --rebase auf develop)
- gco -           (zurück auf den feautre Branch)
- grb develop     (git rebase auf develop)
- gpf             (git push --force-with-lease)

Finale Rebase und Merge (fast forward)

- gco develop     (git checkout develop)
- gup             (git pull --rebase auf develop)
- gco -           (zurück auf den feautre Branch)
- grb develop     (git rebase auf develop)
- gpf             (git push --force-with-lease)
- gco -
- gm FEATURE_NAME (git merge FEATURE_NAME)
- git push origin --delete FEATURE_NAME
- git branch -d FEATURE_NAME

## Referenzen

- [Gitflow features](xocy.md)

## Literatur

- https://danielkummer.github.io/git-flow-cheatsheet/
