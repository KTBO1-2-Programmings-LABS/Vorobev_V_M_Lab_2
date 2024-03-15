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
        printf("������ ����");
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
        printf("������ ����");
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
        printf("������ ����");
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
        printf("������ ����");
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
        printf("������ ����");
    }
    else
    {
        cur_el = cur_el->next;
        *list_begin = cur_el;
    }
}

void print_comands()
{
    printf("�������� �������:\n");
    printf("1 = �������� ����� ������� � ����� ������.\n");
    printf("2 = �������� ����� ������� �� �������� ����� ������.\n");
    printf("3 = �������� ����� ������� ����� �������� � �������� �������������� ������.\n");
    printf("4 = �������� ����� ������� ����� ��������� � �������� �������������� ������.\n");
    printf("5 = �������� ����� ������� � �������� ������.\n");
    printf("6 = ��������� ������� �� �������� ������.\n");
    printf("7 = ��������� ������� � �������� �������������� ������.\n");
    printf("8 = ��������� ������� �� ����� ������.\n");
    printf("9 = ��������� ������� �� ��������� ����� ������.\n");
    printf("10 = ��������� ������� �� ������ ������.\n");
    printf("11 = ������� ������\n");
    printf("0 = ����� ���������\n");
};

void print_recipes(struct recipe* list_begin)
{
    int i = 1;
    struct recipe* cur_el = list_begin;
    if (cur_el == NULL)
    {
        printf("������ ����!");
    }
    else
    {
        while (cur_el != NULL)
        {
            printf("������ � %d: %s\n", i, cur_el->name);
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
    struct recipe a3 = { "�������", "�������,����,����", NULL }, a2 = { "����", "����,����,�����", &a3 }, a1 = { "�����", "����,����,����", &a2 };
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
            printf("������� ��� ");
            scanf("%s", &(new_recipe->name));
            printf("������� ����������� ");
            scanf("%s", &(new_recipe->ingredients));
            add_last(&list_begin, new_recipe);
            amount++;
        }
        if (antwort == 2)
        {
            printf("������� ��� ");
            scanf("%s", &(new_recipe->name));
            printf("������� ����������� ");
            scanf("%s", &(new_recipe->ingredients));
            printf("������� �����, �� ������� ����������� ������� ");
            scanf("%d", &place);
            add_place(&list_begin, new_recipe, place);
            amount++;
        }
        if (antwort == 3)
        {
            printf("������� ��� ");
            scanf("%s", &(new_recipe->name));
            printf("������� ����������� ");
            scanf("%s", &(new_recipe->ingredients));
            printf("������ ����� ���(1) ��� �����������(2) (������� ������ ������ �����) ");
            scanf("%d", &antwort_1);
            printf("������� �������������� ����� (��� ��������) ");
            scanf("%s", &str);
            add_after(&list_begin, new_recipe, antwort_1, str);
            amount++;
        }
        if (antwort == 4)
        {
            printf("������� ��� ");
            scanf("%s", &(new_recipe->name));
            printf("������� ����������� ");
            scanf("%s", &(new_recipe->ingredients));
            printf("������ ����� ���(1) ��� �����������(2) (������� ������ ������ �����) ");
            scanf("%d", &antwort_1);
            printf("������� �������������� ����� (��� ��������) ");
            scanf("%s", &str);
            add_prev(&list_begin, new_recipe, antwort_1, str);
            amount++;
        }
        if (antwort == 5)
        {
            printf("������� ��� ");
            scanf("%s", &(new_recipe->name));
            printf("������� ����������� ");
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
            printf("������ ������� �� �����(1) ��� ������������(2) (������� ������ ������ �����) ");
            scanf("%d", &antwort_1);
            printf("������� �������������� ����� (��� ��������) ");
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
            printf("������� �����, � �������� ������� ������� ");
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