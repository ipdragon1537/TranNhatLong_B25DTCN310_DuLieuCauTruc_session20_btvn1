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
void clearInputBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}
void displayStudents(struct Student students[], int count) {
    printf("\n--- Danh sach sinh vien ---\n");
    if (count == 0) {
        printf("Danh sach trong.\n");
        return;
    }
    for (int i = 0; i < count; i++) {
        printf("\nSinh vien thu %d:\n", i + 1);
        printf("ID: %d\n", students[i].id);
        printf("Ten: %s\n", students[i].name);
        printf("Tuoi: %d\n", students[i].age);
        printf("So dien thoai: %s\n", students[i].phoneNumber);
    }
}
void insertStudent(struct Student students[], int* count, int position, struct Student newStudent) {
    if (position < 1 || position > *count + 1 || *count >= MAX_STUDENTS) {
        printf("Vi tri chen khong hop le hoac mang da day.\n");
        return;
    }
    for (int i = *count; i >= position; i--) {
        students[i] = students[i - 1];
    }
    students[position - 1] = newStudent;
    (*count)++;
    for (int i = position; i < *count; i++) {
        students[i].id = students[i - 1].id + 1;
    }
    printf("Da chen sinh vien thanh cong vao vi tri %d.\n", position);
}
int main() {
    struct Student students[MAX_STUDENTS] = {
        {1, "Nguyen Van A", 20, "0987654321"},
        {2, "Tran Thi B", 21, "0912345678"},
        {3, "Le Van C", 22, "0909876543"},
        {4, "Pham Thi D", 20, "0976543210"},
        {5, "Huynh Van E", 23, "0965432109"}
    };
    int studentCount = 5;
    int position;
    struct Student newStudent;
    displayStudents(students, studentCount);
    printf("\n--- Them sinh vien moi vao vi tri bat ky ---\n");
    printf("Nhap vi tri muon chen (1 den %d): ", studentCount + 1);
    scanf("%d", &position);
    clearInputBuffer();
    printf("Nhap ten sinh vien: ");
    fgets(newStudent.name, sizeof(newStudent.name), stdin);
    newStudent.name[strcspn(newStudent.name, "\n")] = 0;
    printf("Nhap tuoi sinh vien: ");
    scanf("%d", &newStudent.age);
    clearInputBuffer();
    printf("Nhap so dien thoai sinh vien: ");
    fgets(newStudent.phoneNumber, sizeof(newStudent.phoneNumber), stdin);
    newStudent.phoneNumber[strcspn(newStudent.phoneNumber, "\n")] = 0;
    newStudent.id = 0; 
    insertStudent(students, &studentCount, position, newStudent);
    displayStudents(students, studentCount);
    return 0;
}

