# 📦 Distributed Key-Value Storage System (C)

---

## 📌 Overview

This project implements a **distributed key-value storage system simulation** using the C programming language. It demonstrates fundamental concepts of distributed systems such as:

* Consistent Hashing for data distribution
* Replication for fault tolerance
* Failover mechanisms for availability
* Hybrid Data Structures (Trie + HashMap + Linked List)
* File-based persistent storage
* Basic encryption for data security

The system distributes data across multiple nodes and ensures that data remains accessible even when some nodes fail.

---

## 🏗️ System Architecture

The system follows a **modular architecture**:

### 🔹 Core Modules

* **Node Manager**
  Manages node creation, metadata, and status (active/inactive)

* **Consistent Hashing Module**
  Maps keys to nodes using a hash ring

* **Replication Manager**
  Handles writing data to primary and replica nodes

* **Storage Layer**
  Stores data in node-specific files (`nodeX.txt`)

* **Failure Detector**
  Simulates node failures and controls availability

* **Index Manager**
  Uses efficient data structures for fast lookup

* **Encryption Module**
  Encrypts data before storage and decrypts on retrieval

---

## 🔑 Core Concepts

### 1. Consistent Hashing

* Maps keys to nodes in a circular hash space
* Ensures minimal data movement when nodes change
* Enables scalable distribution

---

### 2. Replication

Each key-value pair is stored in:

* **Primary Node**
* **Replica Node(s)** (next nodes in hash ring)

---

### 3. Fault Tolerance (Failover)

* If primary node fails:
  → System automatically reads from replica nodes

---

### 4. Hybrid Data Structure Design

The system uses:

* Trie (for structured lookup)
* HashMap (for fast access)
* Linked List (for collision handling)

---

## ⚙️ Data Structures Used & Time Complexity

---

### 🔹 1. Trie (Prefix Tree)

#### 📌 Usage:

* Key indexing
* Structured or prefix-based lookup

#### ⏱️ Complexity:

| Operation | Complexity |
| --------- | ---------- |
| Insert    | O(L)       |
| Search    | O(L)       |
| Delete    | O(L)       |

👉 L = length of key

#### ✅ Pros:

* No collisions
* Efficient for structured keys

#### ❌ Cons:

* High memory usage
* Overkill for simple numeric keys

---

### 🔹 2. HashMap (Primary Index)

#### 📌 Usage:

* Fast key → value lookup
* Primary indexing structure

#### ⏱️ Complexity:

| Operation | Average | Worst |
| --------- | ------- | ----- |
| Insert    | O(1)    | O(n)  |
| Search    | O(1)    | O(n)  |

---

### 🔗 Collision Handling: Linked List

When multiple keys map to same bucket:

```text
bucket[i] → key1 → key2 → key3
```

#### ⏱️ Complexity:

| Operation | Complexity |
| --------- | ---------- |
| Insert    | O(1)       |
| Search    | O(n)       |
| Delete    | O(n)       |

---

### 🔹 3. File Storage

#### 📌 Usage:

* Persistent storage per node

#### ⏱️ Complexity:

| Operation | Complexity    |
| --------- | ------------- |
| Write     | O(1) (append) |
| Read      | O(n)          |

---

### 🔹 4. Consistent Hashing Ring

#### ⏱️ Complexity:

| Operation   | Complexity |
| ----------- | ---------- |
| Node lookup | O(n)       |
| Optimized   | O(log n)   |

---

## 🔄 Operation Flow

---

### 🟢 PUT(key, value)

1. Hash key → determine primary node
2. Encrypt value
3. Store in primary node
4. Replicate to next node(s)
5. Update index structures

---

### 🔵 GET(key)

1. Hash key → find primary node
2. Try reading from primary
3. If failed → check replica nodes
4. Decrypt value
5. Return result

---

## 🚨 Failure Handling

* Nodes have `isActive` flag
* If a node fails:

  * It is skipped during reads
  * Replica nodes serve data

---

## ⚠️ Limitations & Bottlenecks

---

### 1. File-Based Storage

* Slow for large datasets
* Requires full scan if index fails
* High disk I/O overhead

---

### 2. HashMap Collisions

* Too many collisions → Linked List grows
* Performance degrades to O(n)

---

### 3. Trie Memory Usage

* Each character consumes memory
* Not efficient for numeric-only keys

---

### 4. Linear Hash Ring Traversal

* Node lookup is O(n)
* Not scalable for large clusters

---

### 5. Limited Replication

* Fixed replication (only 1 replica)
* No dynamic replication strategy

---

### 6. No Real Networking

* Nodes are simulated locally
* Not a true distributed system

---

### 7. Weak Failure Detection

* No heartbeat mechanism
* Failures are manually simulated

---

### 8. Concurrency Issues

* No thread safety
* No locking for shared resources

---

### 9. Fixed Memory Buffers

* Example: `char temp[100]`
* Risk of overflow or truncation

---

## 🚀 Possible Improvements

---

### 🔹 1. Optimize Hash Ring

* Use Binary Search / Sorted Map
* Improve lookup from O(n) → O(log n)

---

### 🔹 2. Replace Linked List in HashMap

* Use Balanced Tree (AVL / Red-Black)
* Improve worst-case performance

---

### 🔹 3. Use Better Storage Engine

* Replace files with:

  * LevelDB / RocksDB
  * Faster reads/writes

---

### 🔹 4. Improve Trie

* Use Compressed Trie (Radix Tree)
* Reduce memory usage

---

### 🔹 5. Dynamic HashMap Resizing

* Rehash when load factor increases
* Reduce collisions

---

### 🔹 6. Multi-Replica Support

* Configurable replication factor (N replicas)
* Better fault tolerance

---

### 🔹 7. Add Network Layer

* Use TCP/HTTP communication
* Convert to real distributed system

---

### 🔹 8. Heartbeat-Based Failure Detection

* Automatic node health monitoring

---

### 🔹 9. Concurrency Support

* Use threads (pthreads)
* Add synchronization (locks)

---

### 🔹 10. Strong Consistency Models

* Implement quorum reads/writes
* Ensure consistency across replicas

---

## 🧠 Key Learning Outcomes

* Practical understanding of distributed systems
* Implementation of consistent hashing
* Trade-offs in data structure selection
* Handling replication and failover
* Performance vs complexity decisions

---

## 📌 Conclusion

This project demonstrates a simplified yet powerful model of a distributed key-value storage system. By combining consistent hashing, replication, and hybrid data structures, it achieves basic fault tolerance and efficient data access.

While it is a simulation, it provides a strong foundation for building real-world distributed systems.

---

## 🏷️ Keywords

Distributed Systems, Consistent Hashing, Key-Value Store, Trie, HashMap, Replication, Fault Tolerance, C Programming

---
