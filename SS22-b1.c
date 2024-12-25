#include <stdio.h>
#include <string.h>

struct Student {
    int id;
    char name[50];
    int age;
};

void showStu(struct Student students[], int count);
void addStu(struct Student students[], int *count);
void editStu(struct Student students[], int count);
void deleteStu(struct Student students[], int *count);
void searchStu(struct Student students[], int count);
void sortStu(struct Student students[], int count);

int main() {
    struct Student students[100]; 
    int count = 0; 
    int chose;

    printf("Nhap so luong sinh vien: ");
    scanf("%d", &count);

    for (int i = 0; i < count; i++) {
        printf("Nhap thong tin sinh vien %d\n", i + 1);
        printf("Nhap ID: ");
        scanf("%d", &students[i].id);
        fflush(stdin);
        printf("Nhap ten: ");
        fgets(students[i].name,50,stdin);
        printf("Nhap tuoi: ");
        scanf("%d", &students[i].age);
    }

    do {
        printf("\nMenu\n");
        printf("1. In ra danh sach sinh vien\n");
        printf("2. Them sinh vien\n");
        printf("3. Sua thong tin sinh vien\n");
        printf("4. Xoa sinh vien\n");
        printf("5. Tim kiem sinh vien\n");
        printf("6. Sap xep danh sach sinh vien\n");
        printf("7. Thoat\n");
        printf("Chon chuc nang: ");
        scanf("%d", &chose);

        switch (chose) {
            case 1:
                showStu(students, count);
                break;
            case 2:
                addStu(students, &count);
                break;
            case 3:
                editStu(students, count);
                break;
            case 4:
                deleteStu(students, &count);
                break;
            case 5:
                searchStu(students, count);
                break;
            case 6:
                sortStu(students, count);
                break;
            case 7:
                printf("Ket thuc chuong trinh\n");
                break;
            default:
                printf("Khong thuoc menu\n");
        }
    } while (chose != 7);

    return 0;
}

void showStu(struct Student students[], int count) {
    printf("Danh sach sinh vien:\n");
    for (int i = 0; i < count; i++) {
        printf("ID: %d, Name: %s, Age: %d\n", students[i].id, students[i].name, students[i].age);
    }
}

void addStu(struct Student students[], int *count) {
    if (*count >= 100) {
        printf("Danh sach da day, khong the them sinh vien moi\n");
        return;
    }

    printf("Nhap ID: ");
    scanf("%d", &students[*count].id);
    fflush(stdin);
    printf("Nhap ten: ");
    fgets(students[*count].name,50,stdin);
    printf("Nhap tuoi: ");
    scanf("%d", &students[*count].age);

    (*count)++;
    printf("Da them sinh vien thanh cong!\n");
}

void editStu(struct Student students[], int count) {
    int id, found = 0;
    printf("Nhap ID sinh vien can sua: ");
    scanf("%d", &id);

    for (int i = 0; i < count; i++) {
        if (students[i].id == id) {
        	fflush(stdin);
            printf("Nhap ten moi: ");
            fgets(students[i].name,50,stdin);
            printf("Nhap tuoi moi: ");
            scanf("%d", &students[i].age);
            printf("Da sua thong tin sinh vien thanh cong!\n");
            found = 1;
            break;
        }
    }
    
    if (!found) {
        printf("Khong tim thay sinh vien voi ID %d.\n", id);
    }
}

void deleteStu(struct Student students[], int *count) {
    int id, found = 0;
    printf("Nhap ID sinh vien can xoa: ");
    scanf("%d", &id);

    for (int i = 0; i < *count; i++) {
        if (students[i].id == id) {
            for (int j = i; j < *count - 1; j++) {
                students[j] = students[j + 1];
            }
            (*count)--;
            printf("Da xoa sinh vien voi ID %d.\n", id);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Khong tim thay sinh vien voi ID %d.\n", id);
    }
}

void searchStu(struct Student students[], int count) {
    int id, found = 0;
    printf("Nhap ID sinh vien can tim: ");
    scanf("%d", &id);
    for (int i = 0; i < count; i++) {
        if (students[i].id == id) {
            printf("Sinh vien tim thay: ID: %d\n Name: %s\n Age: %d\n", students[i].id, students[i].name, students[i].age);
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("Khong tim thay sinh vien \n");
    }
}
void sortStu(struct Student students[], int count) {
    struct Student temp;
    for (int i = 0; i < count-i-1; i++) {
        for (int j = i + 1; j < count; j++) {
            if (students[i].id > students[j].id) {
                temp = students[i];
                students[i] = students[j];
                students[j] = temp;
            }
        }
    }
    printf("Danh sach sinh vien da duoc sap xep theo ID.\n");
}

