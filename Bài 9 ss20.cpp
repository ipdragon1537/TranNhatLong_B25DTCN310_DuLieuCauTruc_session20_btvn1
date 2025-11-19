#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX_DISHES 100
#define NAME_LENGTH 50
struct Dish {
    int id;
    char name[NAME_LENGTH];
    float price;
};
struct Dish menu[MAX_DISHES] = {
    {1, "Pho Bo", 50000},
    {2, "Com Tam", 45000},
    {3, "Banh Mi", 25000},
    {4, "Bun Cha", 60000},
    {5, "Hu Tieu", 40000}
};

int dishCount = 5; 
void clearInputBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}
void displayMenu() {
    printf("\n--- MENU MON AN ---\n");
    printf("1. In ra gia tri cac phan tu co trong menu\n");
    printf("2. Them mot phan tu vao vi tri chi dinh\n");
    printf("3. Sua mot phan tu o vi tri chi dinh\n");
    printf("4. Xoa mot phan tu o vi tri chi dinh\n");
    printf("5. Sap xep cac phan tu (Khi lua chon thi hien thi menu con)\n");
    printf("6. Tim kiem phan tu theo name nhap vao\n");
    printf("7. Thoat\n");
    printf("-------------------\n");
    printf("Nhap lua chon cua ban: ");
}
void printDishes() {
    if (dishCount == 0) {
        printf("Menu rong.\n");
        return;
    }
    for (int i = 0; i < dishCount; i++) {
        printf("%d. id: %d, name: %s, price: %.2f\n", i + 1, menu[i].id, menu[i].name, menu[i].price);
    }
}
void addDishAtPosition() {
    if (dishCount >= MAX_DISHES) {
        printf("Menu da day, khong the them mon an moi.\n");
        return;
    }  
    int position;
    printf("Nhap vi tri muon them (1 den %d): ", dishCount + 1);
    scanf("%d", &position);
    clearInputBuffer();
    if (position < 1 || position > dishCount + 1) {
        printf("Vi tri khong hop le.\n");
        return;
    }
    for (int i = dishCount; i >= position; i--) {
        menu[i] = menu[i - 1];
    }
    printf("Nhap ten mon an: ");
    fgets(menu[position - 1].name, sizeof(menu[position - 1].name), stdin);
    menu[position - 1].name[strcspn(menu[position - 1].name, "\n")] = 0;
    printf("Nhap gia mon an: ");
    scanf("%f", &menu[position - 1].price);
    clearInputBuffer();
    for (int i = position - 1; i < dishCount + 1; i++) {
        menu[i].id = i + 1;
    }
    
    dishCount++;
    printf("Da them mon an thanh cong.\n");
}
void editDishAtPosition() {
    int position;
    printf("Nhap vi tri mon an muon sua (1 den %d): ", dishCount);
    scanf("%d", &position);
    clearInputBuffer();
    if (position < 1 || position > dishCount) {
        printf("Vi tri khong hop le.\n");
        return;
    }
    printf("Nhap ten mon an moi: ");
    fgets(menu[position - 1].name, sizeof(menu[position - 1].name), stdin);
    menu[position - 1].name[strcspn(menu[position - 1].name, "\n")] = 0;
    printf("Nhap gia mon an moi: ");
    scanf("%f", &menu[position - 1].price);
    clearInputBuffer();
    printf("Da sua mon an thanh cong.\n");
}
void deleteDishAtPosition() {
    int position;
    printf("Nhap vi tri mon an muon xoa (1 den %d): ", dishCount);
    scanf("%d", &position);
    clearInputBuffer();
    if (position < 1 || position > dishCount) {
        printf("Vi tri khong hop le.\n");
        return;
    }
    for (int i = position - 1; i < dishCount - 1; i++) {
        menu[i] = menu[i + 1];
        menu[i].id = i + 1;
    }
    dishCount--;
    printf("Da xoa mon an thanh cong.\n");
}
void sortDescendingByPrice() {
    for (int i = 0; i < dishCount - 1; i++) {
        for (int j = i + 1; j < dishCount; j++) {
            if (menu[i].price < menu[j].price) {
                struct Dish temp = menu[i];
                menu[i] = menu[j];
                menu[j] = temp;
            }
        }
    }
    printf("Menu da duoc sap xep giam dan theo gia.\n");
}
void sortAscendingByPrice() {
    for (int i = 0; i < dishCount - 1; i++) {
        for (int j = i + 1; j < dishCount; j++) {
            if (menu[i].price > menu[j].price) {
                struct Dish temp = menu[i];
                menu[i] = menu[j];
                menu[j] = temp;
            }
        }
    }
    printf("Menu da duoc sap xep tang dan theo gia.\n");
}
int compareDishes(const void *a, const void *b) {
    return strcmp(((struct Dish*)a)->name, ((struct Dish*)b)->name);
}
void linearSearchByName() {
    char searchName[NAME_LENGTH];
    printf("Nhap ten mon an can tim: ");
    fgets(searchName, sizeof(searchName), stdin);
    searchName[strcspn(searchName, "\n")] = 0;
    int found = 0;
    for (int i = 0; i < dishCount; i++) {
        if (strcmp(menu[i].name, searchName) == 0) {
            printf("Tim thay mon an:\n");
            printf("id: %d, name: %s, price: %.2f\n", menu[i].id, menu[i].name, menu[i].price);
            found = 1;
        }
    }
    if (!found) {
        printf("Khong tim thay mon an co ten '%s'.\n", searchName);
    }
}
void binarySearchByName() {
    char searchName[NAME_LENGTH];
    printf("Nhap ten mon an can tim: ");
    fgets(searchName, sizeof(searchName), stdin);
    searchName[strcspn(searchName, "\n")] = 0;
    qsort(menu, dishCount, sizeof(struct Dish), compareDishes);
    int low = 0, high = dishCount - 1, mid;
    int found = 0;
    while (low <= high) {
        mid = (low + high) / 2;
        int compareResult = strcmp(menu[mid].name, searchName);
        if (compareResult == 0) {
            printf("Tim thay mon an:\n");
            printf("id: %d, name: %s, price: %.2f\n", menu[mid].id, menu[mid].name, menu[mid].price);
            found = 1;
            break;
        } else if (compareResult < 0) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    if (!found) {
        printf("Khong tim thay mon an co ten '%s'.\n", searchName);
    }
}
int main() {
    int choice, subChoice;
    do {
        displayMenu();
        scanf("%d", &choice);
        clearInputBuffer();
        switch (choice) {
            case 1:
                printDishes();
                break;
            case 2:
                addDishAtPosition();
                break;
            case 3:
                editDishAtPosition();
                break;
            case 4:
                deleteDishAtPosition();
                break;
            case 5:
                printf("--- MENU SAP XEP ---\n");
                printf("a. Giam dan theo price\n");
                printf("b. Tang dan theo price\n");
                printf("Nhap lua chon cua ban (a/b): ");
                char subChoiceChar;
                scanf(" %c", &subChoiceChar);
                clearInputBuffer();
                if (subChoiceChar == 'a' || subChoiceChar == 'A') {
                    sortDescendingByPrice();
                } else if (subChoiceChar == 'b' || subChoiceChar == 'B') {
                    sortAscendingByPrice();
                } else {
                    printf("Lua chon khong hop le.\n");
                }
                break;
            case 6:
                printf("--- MENU TIM KIEM ---\n");
                printf("a. Tim kiem tuyen tinh\n");
                printf("b. Tim kiem nhi phan\n");
                printf("Nhap lua chon cua ban (a/b): ");
                scanf(" %c", &subChoiceChar);
                clearInputBuffer();
                if (subChoiceChar == 'a' || subChoiceChar == 'A') {
                    linearSearchByName();
                } else if (subChoiceChar == 'b' || subChoiceChar == 'B') {
                    binarySearchByName();
                } else {
                    printf("Lua chon khong hop le.\n");
                }
                break;
            case 7:
                printf("Thoat chuong trinh.\n");
                break;
            default:
                printf("Lua chon khong hop le. Vui long chon lai.\n");
                break;
        }
    } while (choice != 7);
    return 0;
}

