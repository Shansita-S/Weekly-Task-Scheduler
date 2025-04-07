# Weekly_Task_Scheduler
This C program implements a priority-based weekly task scheduler using priority queues (min-heap) data structure. It allows users to input tasks with priorities and descriptions, then distributes them evenly across the seven days of the week while maintaining priority order.

## Features ✨
- Priority-based task scheduling (1 = highest priority)
- Even distribution of tasks across 7 days
- Dynamic memory management
- Simple command-line interface
- Error handling for edge cases

## Installation ⚙️
1. Clone the repository:
   ```bash
   git clone https://github.com/Shansita-S/weekly-task-scheduler.git

2. Compile the program:
   gcc scheduler.c -o scheduler

 Usage 🖥️
   Run the program and enter tasks:
   ./scheduler

Input format:

[priority] [task description]

Example input:

1 Complete project submission

3 Buy groceries

2 Schedule team meeting

-1  # Ends input

How It Works 🔧

Tasks are stored in a min-heap priority queue

The scheduler:

Processes highest priority tasks first

Distributes tasks round-robin across days

Ensures priority-1 tasks always go to Monday

Output shows the organized weekly schedule

Example 📋

Input:

1 Finalize presentation

3 Gym workout

2 Email client

-1

Output:

Monday:

Priority: 1, Description: Finalize presentation

Tuesday:

Priority: 2, Description: Email client

Wednesday:

Priority: 3, Description: Gym workout

Contributing 🤝
Contributions are welcome! Please:

Fork the repository

Create a new branch

Submit a pull request







