#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <iostream>
#include <locale.h>
#include <cstdlib>

struct recipe
{
    char name[40], ingredients[999];
    struct recipe* next;
};

void add_last(struct recipe** list_begin, struct recipe* new_recipe)
{
    struct recipe* cur_el = *list_begin;
    if (cur_el == NULL)
    {
        *list_begin = new_recipe;
    }
    else
    {
        while (cur_el->next != NULL)
        {
            cur_el = cur_el->next;
        }
        cur_el->next = new_recipe;
    }
    new_recipe->next = NULL;
}

void add_place(struct recipe** list_begin, struct recipe* new_recipe, int place)
{
    struct recipe* cur_el = *list_begin, * cur_el_next;
    int i = 0, new_place = 0;
    if (cur_el == NULL)
    {
        *list_begin = new_recipe;
        new_recipe->next = NULL;
    }
    else
    {
        if (place == 1)
        {
            *list_begin = new_recipe;
            new_recipe->next = cur_el->next;
        }
        else
        {
            new_place = place - 2;
            while (i != new_place)
            {
                cur_el = cur_el->next;
                i++;
            }
            cur_el_next = cur_el->next;
            cur_el->next = new_recipe;
            new_recipe->next = cur_el_next;
        }
    }
}

void add_after(struct recipe** list_begin, struct recipe* new_recipe, int antwort_1, char* str)
{
    struct recipe* cur_el = *list_begin, * cur_el_next;
    if (cur_el == NULL)
    {
        *list_begin = new_recipe;
        new_recipe->next = NULL;
    }
    else
    {
        if (antwort_1 == 1)
        {
            while (strcmp(cur_el->name, str) != 0)
            {
                cur_el = cur_el->next;
            }
        }
        else
        {
            while (strcmp(cur_el->ingredients, str) != 0)
            {
                cur_el = cur_el->next;
            }
        }
        cur_el_next = cur_el->next;
        cur_el->next = new_recipe;
        new_recipe->next = cur_el_next;
    }
}

void add_prev(struct recipe** list_begin, struct recipe* new_recipe, int antwort_1, char* str)
{
    struct recipe* cur_el = *list_begin, * cur_el_next;
    if (cur_el == NULL)
    {
        *list_begin = new_recipe;
        new_recipe->next = NULL;
    }
    else
    {
        cur_el_next = cur_el->next;
        if (antwort_1 == 1)
        {
            while (strcmp(cur_el_next->name, str) != 0)
            {
                cur_el = cur_el->next;
                cur_el_next = cur_el->next;
            }
        }
        else
        {
            while (strcmp(cur_el_next->ingredients, str) != 0)
            {
                cur_el = cur_el->next;
                cur_el_next = cur_el->next;
            }
        }
        cur_el->next = new_recipe;
        new_recipe->next = cur_el_next;
    }
}

void add_ser(struct recipe** list_begin, struct recipe* new_recipe, float amount)
{
    struct recipe* cur_el = *list_begin, * cur_el_next;
    float ser, i = 0;
    if (cur_el == NULL)
    {
        *list_begin = new_recipe;
        new_recipe->next = NULL;
    }
    else
    {
        if ((int)amount % 2 == 0)
        {
            ser = (amount / 2) - 1;
        }
        else
        {
            ser = (amount / 2) - 1.5;
        }
        while (i != ser)
        {
            cur_el = cur_el->next;
            i++;
        }
        cur_el_next = cur_el->next;
        cur_el->next = new_recipe;
        new_recipe->next = cur_el_next;
    }
}

void del_ser(struct recipe** list_begin, float amount)
{
    struct recipe* cur_el = *list_begin, * cur_el_next;
    float ser, i = 0;
    if (cur_el == NULL)
    {
        printf("Список пуст");
    }
    else
    {
        if ((int)amount % 2 == 0)
        {
            ser = (amount / 2) - 2;
        }
        else
        {
            ser = (amount / 2) - 1.5;
        }

        while (i != ser)
        {
            cur_el = cur_el->next;
            i++;
        }
        cur_el_next = cur_el->next;
        cur_el_next = cur_el_next->next;
        cur_el->next = cur_el_next;
    }
}

void del_elem(struct recipe** list_begin, int antwort_1, char* str)
{
    struct recipe* cur_el = *list_begin, * cur_el_next, * cur_el_prev;
    if (cur_el == NULL)
    {
        printf("Список пуст");
    }
    else
    {
        if ((strcmp(cur_el->name, str) == 0) || (strcmp(cur_el->ingredients, str) == 0))
        {
            *list_begin = cur_el->next;
        }
        else
        {
            cur_el_prev = cur_el;
            cur_el = cur_el->next;
            cur_el_next = cur_el->next;
            if (antwort_1 == 1)
            {
                while (strcmp(cur_el->name, str) != 0)
                {
                    cur_el = cur_el->next;
                    cur_el_prev = cur_el_prev->next;
                }
            }
            else
            {
                while (strcmp(cur_el->ingredients, str) != 0)
                {
                    cur_el = cur_el->next;
                    cur_el_prev = cur_el_prev->next;
                }
            }
            cur_el_next = cur_el->next;
            cur_el_prev->next = cur_el_next;
        }
    }
}

void del_last(struct recipe** list_begin)
{
    struct recipe* cur_el = *list_begin, * cur_el_next;
    if (cur_el == NULL)
    {
        printf("Список пуст");
    }
    else
    {
        cur_el_next = cur_el->next;
        while (cur_el_next->next != NULL)
        {
            cur_el_next = cur_el_next->next;
            cur_el = cur_el->next;
        }
        cur_el->next = NULL;
    }
}

void del_place(struct recipe** list_begin, int place)
{
    struct recipe* cur_el = *list_begin, * cur_el_next;
    int i = 0, new_place;
    if (cur_el == NULL)
    {
        printf("Список пуст");
    }
    else
    {
        if (place == 1)
        {
            *list_begin = cur_el->next;
        }
        else
        {
            new_place = place - 2;
            while (i != new_place)
            {
                cur_el = cur_el->next;
                i++;
            }
            cur_el_next = cur_el->next;
            cur_el_next = cur_el_next->next;
            cur_el->next = cur_el_next;
        }
    }
}

void del_first(struct recipe** list_begin)
{
    struct recipe* cur_el = *list_begin;
    if (cur_el == NULL)
    {
        printf("Список пуст");
    }
    else
    {
        cur_el = cur_el->next;
        *list_begin = cur_el;
    }
}

void print_comands()
{
    printf("Выбирите функцию:\n");
    printf("1 = Включить новый элемент в конец списка.\n");
    printf("2 = Включить новый элемент на заданное место списка.\n");
    printf("3 = Включить новый элемент после элемента с заданной информационной частью.\n");
    printf("4 = Включить новый элемент перед элементом с заданной информационной частью.\n");
    printf("5 = Включить новый элемент в середину списка.\n");
    printf("6 = Исключить элемент из середины списка.\n");
    printf("7 = Исключить элемент с заданной информационной частью.\n");
    printf("8 = Исключить элемент из конца списка.\n");
    printf("9 = Исключить элемент из заданного места списка.\n");
    printf("10 = Исключить элемент из головы списка.\n");
    printf("11 = Вывести список\n");
    printf("0 = Конец программы\n");
};

void print_recipes(struct recipe* list_begin)
{
    int i = 1;
    struct recipe* cur_el = list_begin;
    if (cur_el == NULL)
    {
        printf("Список пуст!");
    }
    else
    {
        while (cur_el != NULL)
        {
            printf("Рецепт № %d: %s\n", i, cur_el->name);
            printf("%s\n", cur_el->ingredients);
            printf("------\n");
            cur_el = cur_el->next;
            i++;
        }
    }
}

int main()
{
    setlocale(LC_ALL, "Russian");
    system("chcp 1251");
    struct recipe a3 = { "Пирожки", "Начинка,мука,яйца", NULL }, a2 = { "Торт", "Яйца,крем,орехи", &a3 }, a1 = { "Блины", "Мука,яйца,вода", &a2 };
    struct recipe* new_recipe, * list_begin = &a1;
    char str[999];
    int antwort = -1, place = 0, antwort_1 = 0;
    float amount = 3;
    while (antwort != 0)
    {
        print_comands();
        scanf("%d", &antwort);
        new_recipe = (struct recipe*)malloc(sizeof(struct recipe));
        if (antwort == 1)
        {
            printf("Введите имя ");
            scanf("%s", &(new_recipe->name));
            printf("Введите ингредиенты ");
            scanf("%s", &(new_recipe->ingredients));
            add_last(&list_begin, new_recipe);
            amount++;
        }
        if (antwort == 2)
        {
            printf("Введите имя ");
            scanf("%s", &(new_recipe->name));
            printf("Введите ингредиенты ");
            scanf("%s", &(new_recipe->ingredients));
            printf("Введите место, на которое поместитить элемент ");
            scanf("%d", &place);
            add_place(&list_begin, new_recipe, place);
            amount++;
        }
        if (antwort == 3)
        {
            printf("Введите имя ");
            scanf("%s", &(new_recipe->name));
            printf("Введите ингредиенты ");
            scanf("%s", &(new_recipe->ingredients));
            printf("Хотите найти имя(1) или ингредиенты(2) (введите только нужную цифру) ");
            scanf("%d", &antwort_1);
            printf("Введите информационную часть (без пробелов) ");
            scanf("%s", &str);
            add_after(&list_begin, new_recipe, antwort_1, str);
            amount++;
        }
        if (antwort == 4)
        {
            printf("Введите имя ");
            scanf("%s", &(new_recipe->name));
            printf("Введите ингредиенты ");
            scanf("%s", &(new_recipe->ingredients));
            printf("Хотите найти имя(1) или ингредиенты(2) (введите только нужную цифру) ");
            scanf("%d", &antwort_1);
            printf("Введите информационную часть (без пробелов) ");
            scanf("%s", &str);
            add_prev(&list_begin, new_recipe, antwort_1, str);
            amount++;
        }
        if (antwort == 5)
        {
            printf("Введите имя ");
            scanf("%s", &(new_recipe->name));
            printf("Введите ингредиенты ");
            scanf("%s", &(new_recipe->ingredients));
            add_ser(&list_begin, new_recipe, amount);
            amount++;
        }
        if (antwort == 6)
        {
            del_ser(&list_begin, amount);
            amount--;
        }
        if (antwort == 7)
        {
            printf("Хотите удалить по имени(1) или ингредиентам(2) (введите только нужную цифру) ");
            scanf("%d", &antwort_1);
            printf("Введите информационную часть (без пробелов) ");
            scanf("%s", &str);
            del_elem(&list_begin, antwort_1, str);
            amount--;
        }
        if (antwort == 8)
        {
            del_last(&list_begin);
            amount--;
        }
        if (antwort == 9)
        {
            printf("Введите место, с которого удалить элемент ");
            scanf("%d", &place);
            del_place(&list_begin, place);
            amount--;
        }
        if (antwort == 10)
        {
            del_first(&list_begin);
            amount--;
        }
        if (antwort == 11)
        {
            print_recipes(list_begin);
        }
    }
    return 0;
}