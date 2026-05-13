# Supermarket Console Simulation (C++)

Author: Omar Magdy Abdelzaher  
Faculty of computer science — Ain Shams University  
Expected Graduation: 2029  
---

## Overview

A console-based supermarket simulation system implemented in C++ using layered architecture principles.

The project focuses on clean separation of responsibility between system layers and selecting data structures based on time complexity requirements.

It simulates inventory management, cart operations, persistence, and analytics using custom Binary Search Trees.

This project is part of a self-directed C++ system design track focused on layered architecture, separation of responsibility between components, and performance-aware data structure selection based on time complexity analysis.

---

## Architecture

Project structure follows a layered system design:

classes/

domain/ → business entities (Product, Category, Cart, Order, User)

persistence/ → file loading & saving

BST_analytics/ → custom BST-based ranking engine

store/ → inventory and checkout orchestration

interface/ → console menus and navigation

Program/ → orchestrate between every layer inside the main loop and subloops
---

## Features

Inventory management using unordered_map for avarage O(1) lookup

Category-based restocking thresholds

Cart system with undo / redo support using stack

Sales analytics using custom Binary Search Trees

FIFO order processing simulation using queue

Persistent storage for products, categories, and sales

Automatic ID synchronization after loading data

---

## Data Structures Used

unordered_map → fast product/category lookup O(1)

vector → cart storage

stack → undo / redo operations

queue → FIFO order processing simulation

Binary Search Tree → sales and price analytics

---

## Design Focus

This project emphasizes:

time complexity awareness when selecting data structures

clean separation of responsibility between system layers

encapsulation of domain logic inside entity classes

modular system architecture suitable for extension

---

## Project Status

Completed.
