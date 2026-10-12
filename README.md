# Data Structures & Algorithms in C

Implementations of classic data structures in **C**, written from scratch during the
**Algorithms and Data Structures** course of my **Master's in Computer Science** at
**Universidade Federal Fluminense (UFF)**, Rio de Janeiro, Brazil (2023).

The focus is on manual memory management (`malloc`/`free`), pointer manipulation,
recursion and building higher-level abstractions on top of lower-level ones
(for example, stacks and queues built on a deque, a queue built from two stacks,
and a stack built from two queues).

> **Note on language:** the course was taught in Portuguese, so file names, identifiers
> and comments are in Portuguese. See the [glossary](#glossary-portuguese--english) below.

---

## Highlights

- **B-tree**: insertion with node splitting, removal with redistribution and merge,
  search and in-order traversal.
- **Hash tables**: separate chaining plus open addressing with **linear probing**,
  **quadratic probing** and **double hashing**, and a **Bloom filter** used as a
  weak-password checker.
- **Binary trees**: traversals, mirror, copy and equality, height, balance factor,
  BST and AVL property checks, level-order printing, node coloring.
- **Graphs**: adjacency-list graph with node and edge insertion, removal and search.
- **Composed structures**: stack built from two queues, queue built from two stacks,
  min-stack, and an **infix to Reverse Polish Notation** converter built on a deque.
- **Singly linked list** with 30+ operations (recursive and iterative), including
  reverse, merge and interleave, split and remove duplicates.

## Repository structure

```
data-structures/
├── linked-lists/
│   ├── singly-linked-list/        # TLSE: 30+ operations, recursive and iterative
│   ├── doubly-linked-list/        # TLSED
│   └── array-based-linked-list/   # TLSEV: linked list stored in an array (cursor-based)
├── deque/                         # DEQUE: double-ended queue (base for stacks and queues)
├── stacks/
│   ├── array-stack/               # dynamic-array stack
│   ├── linked-list-stack/
│   ├── deque-based-stack/
│   ├── stack-with-two-queues/
│   ├── min-stack/                 # O(1) minimum via auxiliary deque
│   ├── stack-reversal/
│   └── reverse-polish-notation/   # infix to postfix (RPN) conversion
├── queues/
│   ├── array-queue/               # dynamic-array (circular) queue
│   ├── linked-list-queue/
│   ├── deque-based-queue/
│   ├── queue-with-two-stacks/
│   └── queue-reversal/
├── trees/
│   ├── binary-tree/               # TAB: general binary tree, many operations
│   ├── binary-tree-coloring/      # TAB variant: node-coloring exercise
│   ├── binary-search-tree/        # TABB
│   └── b-tree/                    # TARVB
├── hash-tables/
│   ├── separate-chaining/         # TABHASH: chaining with linked lists
│   └── hashing-strategies/        # linear and quadratic probing, double hashing, Bloom filter
├── graphs/                        # TG: adjacency-list graph
└── heap/                          # binary max-heap (heapify)

exams/          # my solutions to the course's three exams (P1, P2, P3)
exercises/
├── c-fundamentals/   # C exercises: strings, arrays, pointers, primes, online-judge problems
├── patient-queue/    # hospital triage simulation using queues and stacks
├── minesweeper/
├── sudoku/           # work in progress (does not compile yet)
└── misc/
```

Each folder under `data-structures/` is a self-contained project with the layout
`include/` (header with the public API), `src/` (implementation plus a `teste_*.c`
driver program) and a `Makefile`.

## Building and running

Requirements: `gcc` and `make` (Linux, macOS, or Windows with MinGW).

```bash
cd data-structures/trees/b-tree
make        # builds output/main
make run    # builds and runs the interactive test program
make clean
```

Single-file programs (such as `heap/` and `hashing-strategies/`) can be compiled directly:

```bash
gcc -Wall -o heap data-structures/heap/heap.c
```

All projects under `data-structures/` compile with `gcc -Wall -Wextra`.

## Glossary (Portuguese → English)

| Portuguese | English | | Portuguese | English |
|---|---|---|---|---|
| `TLSE` (lista simplesmente encadeada) | singly linked list | | `insere` | insert |
| `TLSED` (lista duplamente encadeada) | doubly linked list | | `retira` / `remove` | remove |
| `TLSEV` (lista encadeada em vetor) | array-based linked list | | `busca` | search |
| `PILHA` / `TP` | stack | | `inicializa` | initialize |
| `FILA` / `TF` | queue | | `libera` | free |
| `TAB` (árvore binária) | binary tree | | `imprime` | print |
| `TABB` (árvore binária de busca) | binary search tree | | `vazia` | is empty |
| `TARVB` (árvore B) | B-tree | | `topo` | top |
| `TABHASH` / `TH` | hash table | | `inverte` | reverse |
| `TG` (grafo) | graph | | `teste_*.c` | test or driver program |

## Credits

Some files in `data-structures/hash-tables/hashing-strategies/` started from lesson
code by **Wagner Gaspar** (*Programe seu Futuro*), as noted in their headers, and were
then extended and modified by me. Other files that were adapted from public
references say so in a comment that links to the source.

## License

[MIT](LICENSE). Third-party portions mentioned above remain under their authors' terms.
