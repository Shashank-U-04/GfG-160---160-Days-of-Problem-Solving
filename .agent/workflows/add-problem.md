---
description: How to add a new GFG 160 problem to this repository
---

# Adding a New GFG 160 Problem

Follow these steps when the user provides a new problem to add:

## 1. Determine the Problem Number
- Check the Arrays folder (or relevant topic folder) for the last problem number
- Increment by 1 for the new problem

## 2. Create the Solution File
- Create `Arrays/XX_Problem_Name.cpp` (replace XX with problem number, use underscores in name)
- Include: problem description, examples, constraints, company tags, topic tags
- Include: detailed approach explanation
- Include: clean, well-commented solution code
- Include: time and space complexity analysis

## 3. Update README.md
- Update the progress badge (e.g., `5%2F160` → `6%2F160`)
- Add the new problem to the Problems Solved table under the appropriate topic

// turbo-all
## 4. Commit and Push Changes
Always commit and push after adding a problem to maintain the GitHub streak:

```powershell
git add .
git commit -m "feat: Add Problem XX - Problem Name"
git push
```

**IMPORTANT**: Never skip this step! The user wants to maintain their GitHub streak.
