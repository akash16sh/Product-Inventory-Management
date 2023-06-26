#include <iostream>
using namespace std;

struct Product {
    int id;
    string name;
    float price;
    int quantity;
};

const int MAX_PRODUCTS = 100;  // Maximum number of products

Product inventory[MAX_PRODUCTS];
int productCount = 0;  // Number of products in the inventory

void addProduct() {
    if (productCount >= MAX_PRODUCTS) {
        cout << "Inventory is full. Cannot add more products." << endl;
        return;
    }

    Product product;
    cout << "Enter product ID: ";
    cin >> product.id;
    cin.ignore();
    cout << "Enter product name: ";
    getline(cin, product.name);
    cout << "Enter product price: ";
    cin >> product.price;
    cout << "Enter product quantity: ";
    cin >> product.quantity;

    inventory[productCount] = product;
    productCount++;
    cout << "Product added successfully." << endl;
}

void viewProducts() {
    if (productCount == 0) {
        cout << "No products in the inventory." << endl;
        return;
    }

    cout << "Product Inventory:" << endl;
    for (int i = 0; i < productCount; i++) {
        cout << "ID: " << inventory[i].id << endl;
        cout << "Name: " << inventory[i].name << endl;
        cout << "Price: " << inventory[i].price << endl;
        cout << "Quantity: " << inventory[i].quantity << endl;
        cout << endl;
    }
}

void searchProduct() {
    if (productCount == 0) {
        cout << "No products in the inventory." << endl;
        return;
    }

    int searchId;
    cout << "Enter product ID to search: ";
    cin >> searchId;

    bool found = false;
    for (int i = 0; i < productCount; i++) {
        if (inventory[i].id == searchId) {
            cout << "Product Found:" << endl;
            cout << "ID: " << inventory[i].id << endl;
            cout << "Name: " << inventory[i].name << endl;
            cout << "Price: " << inventory[i].price << endl;
            cout << "Quantity: " << inventory[i].quantity << endl;
            found = true;
            break;
        }
    }

    if (!found) {
        cout << "Product not found." << endl;
    }
}

void updateProduct() {
    if (productCount == 0) {
        cout << "No products in the inventory." << endl;
        return;
    }

    int updateId;
    cout << "Enter product ID to update: ";
    cin >> updateId;

    bool found = false;
    for (int i = 0; i < productCount; i++) {
        if (inventory[i].id == updateId) {
            cout << "Enter new product name: ";
            cin.ignore();
            getline(cin, inventory[i].name);
            cout << "Enter new product price: ";
            cin >> inventory[i].price;
            cout << "Enter new product quantity: ";
            cin >> inventory[i].quantity;
            cout << "Product details updated successfully." << endl;
            found = true;
            break;
        }
    }

    if (!found) {
        cout << "Product not found." << endl;
    }
}

void deleteProduct() {
    if (productCount == 0) {
        cout << "No products in the inventory." << endl;
        return;
    }

    int deleteId;
    cout << "Enter product ID to delete: ";
    cin >> deleteId;

    bool found = false;
    for (int i = 0; i < productCount; i++) {
        if (inventory[i].id == deleteId) {
            for (int j = i; j < productCount - 1; j++) {
                inventory[j] = inventory[j + 1];
            }
            productCount--;
            cout << "Product deleted successfully." << endl;
            found = true;
            break;
        }
    }

    if (!found) {
        cout << "Product not found." << endl;
    }
}

int main() {
    int choice;

    while (true) {
        cout << "Product Inventory Management System" << endl;
        cout << "1. Add Product" << endl;
        cout << "2. View Products" << endl;
        cout << "3. Search Product" << endl;
        cout << "4. Update Product" << endl;
        cout << "5. Delete Product" << endl;
        cout << "6. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                addProduct();
                break;
            case 2:
                viewProducts();
                break;
            case 3:
                searchProduct();
                break;
            case 4:
                updateProduct();
                break;
            case 5:
                deleteProduct();
                break;
            case 6:
                cout << "Thank you for using the Product Inventory Management System." << endl;
                return 0;
            default:
                cout << "Invalid choice. Please try again." << endl;
                break;
        }

        cout << endl;
    }
}

