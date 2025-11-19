#include <stdio.h>
#include <string.h>
#define MAX_STUDENTS 50
#define NAME_LENGTH 50
#define PHONE_LENGTH 15
struct Student {
    int id;
    char name[NAME_LENGTH];
    int age;
    char phoneNumber[PHONE_LENGTH];
};

int main() {
    struct Student students[MAX_STUDENTS] = {
        {1, "Nguyen Van A", 20, "0987654321"},
        {2, "Tran Thi B", 21, "0912345678"},
        {3, "Le Van C", 22, "0909876543"},
        {4, "Pham Thi D", 20, "0976543210"},
        {5, "Huynh Van E", 23, "0965432109"}
	};
    printf("--- Thong tin cua cac sinh vien da khoi tao ---\n");
    for (int i = 0; i < 5; i++) {
        printf("\nSinh vien thu %d:\n", i + 1);
        printf("ID: %d\n", students[i].id);
        printf("Ten: %s\n", students[i].name);
        printf("Tuoi: %d\n", students[i].age);
        printf("So dien thoai: %s\n", students[i].phoneNumber);
    }
    printf("\n\n--- Kiem tra phan tu thu 6 (phan tu chua duoc khoi tao) ---\n");
    printf("ID: %d\n", students[5].id);
    printf("Ten: %s\n", students[5].name);
    return 0;
}

