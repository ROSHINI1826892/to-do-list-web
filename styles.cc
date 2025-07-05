  <style>
        body {
            font-family: 'Inter', sans-serif;
            background-color: #f0f2f5;
            display: flex;
            justify-content: center;
            align-items: flex-start; /* Align to top for better mobile view */
            min-height: 100vh;
            padding: 20px;
            box-sizing: border-box;
        }
        .container {
            background-color: #ffffff;
            padding: 2rem;
            border-radius: 1rem;
            box-shadow: 0 10px 25px rgba(0, 0, 0, 0.1);
            width: 100%;
            max-width: 600px;
            margin-top: 20px; /* Add some margin from the top */
        }
        .task-item {
            display: flex;
            align-items: center;
            justify-content: space-between;
            background-color: #f9fafb;
            padding: 1rem;
            border-radius: 0.75rem;
            margin-bottom: 0.75rem;
            box-shadow: 0 4px 6px rgba(0, 0, 0, 0.05);
            transition: all 0.2s ease-in-out;
            border: 1px solid #e5e7eb;
        }
        .task-item:hover {
            transform: translateY(-2px);
            box-shadow: 0 6px 12px rgba(0, 0, 0, 0.08);
        }
        .task-item.completed {
            background-color: #e0ffe0; /* Light green for completed tasks */
            text-decoration: line-through;
            opacity: 0.7;
            border-color: #a7f3d0;
        }
        .task-content {
            flex-grow: 1;
            display: flex;
            flex-direction: column;
            gap: 0.25rem;
        }
        .task-text {
            font-weight: 500;
            color: #374151;
            word-break: break-word; /* Ensure long words break */
        }
        .task-date {
            font-size: 0.85rem;
            color: #6b7280;
        }
        .action-buttons {
            display: flex;
            gap: 0.5rem;
            flex-shrink: 0; /* Prevent buttons from shrinking */
        }
        .btn {
            padding: 0.6rem 1rem;
            border-radius: 0.5rem;
            font-weight: 600;
            cursor: pointer;
            transition: background-color 0.2s ease-in-out, transform 0.1s ease-in-out;
            box-shadow: 0 2px 4px rgba(0, 0, 0, 0.05);
        }
        .btn:active {
            transform: translateY(1px);
        }
        .btn-add {
            background-color: #4f46e5;
            color: white;
        }
        .btn-add:hover {
            background-color: #4338ca;
        }
        .btn-complete {
            background-color: #10b981;
            color: white;
        }
        .btn-complete:hover {
            background-color: #059669;
        }
        .btn-delete {
            background-color: #ef4444;
            color: white;
        }
        .btn-delete:hover {
            background-color: #dc2626;
        }
        input[type="text"], input[type="date"] {
            flex-grow: 1;
            padding: 0.75rem 1rem;
            border: 1px solid #d1d5db;
            border-radius: 0.5rem;
            font-size: 1rem;
            color: #374151;
            outline: none;
            transition: border-color 0.2s ease-in-out, box-shadow 0.2s ease-in-out;
        }
        input[type="text"]:focus, input[type="date"]:focus {
            border-color: #6366f1;
            box-shadow: 0 0 0 3px rgba(99, 102, 241, 0.2);
        }
        .input-group {
            display: flex;
            gap: 0.75rem;
            margin-bottom: 1.5rem;
            flex-wrap: wrap; /* Allow wrapping on small screens */
        }
        .input-group > * {
            flex: 1 1 auto; /* Allow items to grow and shrink */
            min-width: 150px; /* Minimum width before wrapping */
        }
        .modal {
            position: fixed;
            top: 0;
            left: 0;
            width: 100%;
            height: 100%;
            background-color: rgba(0, 0, 0, 0.6);
            display: flex;
            justify-content: center;
            align-items: center;
            z-index: 1000;
            opacity: 0;
            visibility: hidden;
            transition: opacity 0.3s ease-in-out, visibility 0.3s ease-in-out;
        }
        .modal.show {
            opacity: 1;
            visibility: visible;
        }
        .modal-content {
            background-color: white;
            padding: 2rem;
            border-radius: 1rem;
            box-shadow: 0 10px 30px rgba(0, 0, 0, 0.2);
            text-align: center;
            max-width: 400px;
            width: 90%;
            transform: translateY(-20px);
            transition: transform 0.3s ease-in-out;
        }
        .modal.show .modal-content {
            transform: translateY(0);
        }
        .modal-buttons {
            display: flex;
            justify-content: center;
            gap: 1rem;
            margin-top: 1.5rem;
        }
        .modal-buttons .btn {
            flex: 1;
        }
    </style>
</head>
<body>
    <div class="container">
        <h1 class="text-3xl font-bold text-gray-800 mb-6 text-center">My To-Do List</h1>

        <div class="input-group">
            <input type="text" id="taskInput" placeholder="Add a new task..." class="focus:border-indigo-500">
            <input type="date" id="dueDateInput" class="focus:border-indigo-500">
            <button id="addTaskBtn" class="btn btn-add">Add Task</button>
        </div>

        <ul id="taskList" class="space-y-3">
            <!-- Tasks will be loaded here -->
        </ul>
    </div>

    <!-- Confirmation Modal -->
    <div id="confirmationModal" class="modal">
        <div class="modal-content">
            <p class="text-lg text-gray-700 mb-4">Are you sure you want to delete this task?</p>
            <div class="modal-buttons">
                <button id="confirmDeleteBtn" class="btn btn-delete">Delete</button>
                <button id="cancelDeleteBtn" class="btn btn-add">Cancel</button>
            </div>
        </div>
    </div>

