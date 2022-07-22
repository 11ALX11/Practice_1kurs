#include <iostream>

using namespace std;

int input_universum[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11};
    const int input_universum_size = 11;
int input_A[] = {1, 2, 3, 4, 5, 6}; const int input_A_size = 6;
int input_B[] = {5, 6, 7, 8};       const int input_B_size = 4;
int input_C[] = {2, 3, 5, 7, 8};    const int input_C_size = 5;

//отображение в двоичном представлении
void convert_to_bin (unsigned decimal_value);

//конвертация в битовую маску
int convert_to_bit_mask(const int* set, const int set_size);

//булеан (функция возвращает битовые маски)
int* create_boolean(const int* set, const int set_size);

//объединение, пересечение, разность, симметрическую разность (функции возвращают битовые маски)
int unite(const int* set1, const int set1_size, const int* set2, const int set2_size);
int intersection(const int* set1, const int set1_size, const int* set2, const int set2_size);
int difference(const int* set1, const int set1_size, const int* set2, const int set2_size);
int symmetrical_difference(const int* set1, const int set1_size, const int* set2, const int set2_size);
int addition(const int* set1, const int set1_size, const int* set2, const int set2_size);

int main()
{
    int boolean_size = 1 << (input_A_size);
    int* boolean = create_boolean(input_A, input_A_size);
    for (int i = 0; i < boolean_size; i++) {
        convert_to_bin(boolean[i]);
        cout << endl;
    }
}

void convert_to_bin (unsigned decimal_value)
{
   char digit = (decimal_value % 2) ? '1' : '0';
   unsigned next = decimal_value / 2;
   if (next)
   {
      convert_to_bin (next);
   }
   printf("%c", digit);
}

int convert_to_bit_mask(const int* set, const int set_size) {
    int bitmask = 0;

    for (int j = 0; j < set_size; j++) {
            bitmask += 1 << j;
    }

    return bitmask;
}

int* create_boolean(const int* set, const int set_size) {
    int bitmask = convert_to_bit_mask(set, set_size);
    
    int boolean_size = 1 << (set_size);
    int* boolean = new int[boolean_size];

    for (int i = 0; i < boolean_size; i++) {
        boolean[i] = 0;
    }

    int bm = bitmask;
    int n = 0;
    while (bm > 0) {
        bm = bm >> 1;
        n++;
    }

    int k = 1;
    for (int j = 0; j <= n; j++) {
        int bit = 1 << j;
        int d = 1 << k;
        if (bitmask%2) {
            k++;
            for (int i = 0; i < boolean_size; i++) {
                if (i%d < d/2) boolean[i] += bit;
            }
        }
        bitmask = bitmask >> 1;
    }

    return boolean;
}

int unite(const int* set1, const int set1_size, const int* set2, const int set2_size) {
    int bitmask1 = convert_to_bit_mask(set1, set1_size);
    int bitmask2 = convert_to_bit_mask(set2, set2_size);
    return bitmask1 | bitmask2;
}
int intersection(const int* set1, const int set1_size, const int* set2, const int set2_size) {
    int bitmask1 = convert_to_bit_mask(set1, set1_size);
    int bitmask2 = convert_to_bit_mask(set2, set2_size);
    return bitmask1 & bitmask2;
}
int difference(const int* set1, const int set1_size, const int* set2, const int set2_size) {
    int bitmask1 = convert_to_bit_mask(set1, set1_size);
    int bitmask2 = convert_to_bit_mask(set2, set2_size);
    return bitmask1 & (~(bitmask1 & bitmask2));
}
int symmetrical_difference(const int* set1, const int set1_size, const int* set2, const int set2_size) {
    int bitmask1 = convert_to_bit_mask(set1, set1_size);
    int bitmask2 = convert_to_bit_mask(set2, set2_size);
    return (bitmask1 & (~(bitmask1 & bitmask2))) | (bitmask2 & (~(bitmask1 & bitmask2)));
}
int addition(const int* set1, const int set1_size, const int* set2, const int set2_size) {
    int bitmask1 = convert_to_bit_mask(set1, set1_size);
    int bitmask2 = convert_to_bit_mask(set2, set2_size);
    return bitmask1 & (~(bitmask1 & bitmask2));
}
