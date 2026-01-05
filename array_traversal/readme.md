# Patterns And Algorithms
--- 

## Pattern: Running State & Best-So-Far

### Essence
Separate the problem into:
- Past (what has already been evaluated)
- Present/Future (what is currently being built)

### Running State
- Represents a candidate under construction
- Temporary and discardable
- Used to decide whether continuing is beneficial

### Best-So-Far
- Stores the best valid result encountered so far
- Independent of current running state
- Never decreases in quality

### Core Rule
Before discarding a running state:
- Compare it with best-so-far
- Preserve its value if it is better

### Why Discarding Works
If the running state becomes harmful (e.g., negative in sum problems),
including it will only worsen future outcomes.
Discarding does not erase history because best-so-far is already saved.

### Key Dependency
This pattern relies on **consecutiveness**.
It does NOT work for non-consecutive selection problems.

### Typical Use Cases
- Maximum / minimum subarray problems
- Greedy optimization
- Dynamic programming with local decisions

---

## Pattern: Global Knowledge + Incremental Build

### Essence
Use information about the whole to simplify local decisions.

### Global Information
- Computed once
- Constant during the main loop
- Represents a fixed truth about the input

Examples:
- Total sum of array
- Total count
- Total frequency

### Incremental State
- Built step by step during traversal
- Represents partial progress (prefix)

### Derivation Idea
Instead of computing both sides of a comparison:
- Build one side incrementally
- Derive the other using global information

### Core Rule
If:
- total = global constant
- left = incremental prefix

Then:
- right can be derived, not recomputed

### Why This Avoids Nested Loops
Because each required value is either:
- already known
- or computed in O(1)

### Typical Use Cases
- Balance index problems
- Prefix sums
- Range queries
- Sliding window foundations

