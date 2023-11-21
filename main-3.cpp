#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

struct Product {
    std::string name;
    double price;
    int quantity;
};

void addProduct(std::ofstream& file) {
    std::string name;
    double price;
    int quantity;

    std::cout << "Enter product name: ";
    std::cin.ignore();
    std::getline(std::cin, name);

    std::cout << "Enter product price: ";
    std::cin >> price;

    std::cout << "Enter product quantity: ";
    std::cin >> quantity;

    file << name << "," << price << "," << quantity << std::endl;
}

void searchProduct(const std::string& productName, std::ifstream& file) {
    std::string line;
    std::vector<Product> products;

    while (std::getline(file, line)) {
        std::string name = line.substr(0, line.find(","));
        double price = std::stod(line.substr(line.find(",") + 1, line.rfind(",") - line.find(",") - 1));
        int quantity = std::stoi(line.substr(line.rfind(",") + 1));

        products.push_back({name, price, quantity});
    }

    auto it = std::find_if(products.begin(), products.end(), [productName](const Product& p) {
        return p.name == productName;
    });

    if (it != products.end()) {
        std::cout << "Product found:" << std::endl;
        std::cout << "Name: " << it->name << std::endl;
        std::cout << "Price: " << it->price << std::endl;
        std::cout << "Quantity: " << it->quantity << std::endl;
    } else {
        std::cout << "Product not found." << std::endl;
    }
}

void sortProducts(const std::string& sortBy, std::ifstream& file) {
    std::string line;
    std::vector<Product> products;

    while (std::getline(file, line)) {
        std::string name = line.substr(0, line.find(","));
        double price = std::stod(line.substr(line.find(",") + 1, line.rfind(",") - line.find(",") - 1));
        int quantity = std::stoi(line.substr(line.rfind(",") + 1));

        products.push_back({name, price, quantity});
    }

    if (sortBy == "price") {
        std::sort(products.begin(), products.end(), [](const Product& p1, const Product& p2) {
            return p1.price < p2.price;
        });
    } else if (sortBy == "quantity") {
        std::sort(products.begin(), products.end(), [](const Product& p1, const Product& p2) {
            return p1.quantity < p2.quantity;
        });
    }

    std::ofstream outputFile("output.txt");
    for (const auto& product : products) {
        outputFile << product.name << "," << product.price << "," << product.quantity << std::endl;
    }
}

int main() {
        std::ofstream file("products.txt", std::ios::app);

    if (!file) {
        std::cout << "Failed to open file." << std::endl;
        return 1;
    }

    while (true) {
        std::cout << "Menu:" << std::endl;
        std::cout << "1. Add product" << std::endl;
        std::cout << "2. Search product by name" << std::endl;
        std::cout << "3. Sort products by price" << std::endl;
        std::cout << "4. Sort products by quantity" << std::endl;
        std::cout << "5. Exit" << std::endl;
        std::cout << "Choose an option: ";
    

        int option;
        std::cin >> option;

        switch (option) {
            case 1:
                addProduct(file);
                break;
            case 2: {
                std::cin.ignore(); // Ignore newline character from previous input
                std::string productName;
                std::cout << "Enter product name to search: ";
                std::getline(std::cin, productName);
                std::ifstream inputFile("products.txt");
                searchProduct(productName, inputFile);
                inputFile.close();
                break;
            }
            case 3: {
                std::ifstream inputFile("products.txt");
                sortProducts("price", inputFile);
                inputFile.close();
                break;
            }
            case 4: {
                std::ifstream inputFile("products.txt");
                sortProducts("quantity", inputFile);
                inputFile.close();
                break;
            }
            case 5:
                file.close();
                return 0;
            default:
                std::cout << "Invalid option. Please try again." << std::endl;
        }
    }
}




