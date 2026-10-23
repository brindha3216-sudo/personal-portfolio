
# Personal Expense Tracker
# Developed using Python

expenses = []

def add_expense():
    category = input("Enter expense category: ")
    amount = float(input("Enter amount (Rs.): "))
    description = input("Enter description: ")

    if amount <= 0:
        print("Please enter a valid positive amount.")
        return

    expense = {
        "category": category,
        "amount": amount,
        "description": description
    }

    expenses.append(expense)
    print("Expense added successfully!")

def view_expenses():
    if not expenses:
        print("No expenses recorded yet.")
        return

    print("\n===== EXPENSE HISTORY =====")

    for index, expense in enumerate(expenses, start=1):
        print(f"\nExpense {index}")
        print("Category:", expense["category"])
        print("Amount: Rs.", round(expense["amount"], 2))
        print("Description:", expense["description"])

def show_total():
    total = sum(expense["amount"] for expense in expenses)
    print(f"\nTotal Expenses: Rs. {total:.2f}")

def category_summary():
    if not expenses:
        print("No expenses available.")
        return

    summary = {}

    for expense in expenses:
        category = expense["category"].title()
        summary[category] = (
            summary.get(category, 0) + expense["amount"]
        )

    print("\n===== CATEGORY SUMMARY =====")

    for category, amount in summary.items():
        print(f"{category}: Rs. {amount:.2f}")

while True:
    print("\n===== PERSONAL EXPENSE TRACKER =====")
    print("1. Add Expense")
    print("2. View Expenses")
    print("3. Show Total Expenses")
    print("4. Category-wise Summary")
    print("5. Exit")

    choice = input("Enter your choice: ")

    if choice == "1":
        add_expense()
    elif choice == "2":
        view_expenses()
    elif choice == "3":
        show_total()
    elif choice == "4":
        category_summary()
    elif choice == "5":
        print("Thank you for using Expense Tracker!")
        break
    else:
        print("Invalid choice! Please try again.")
