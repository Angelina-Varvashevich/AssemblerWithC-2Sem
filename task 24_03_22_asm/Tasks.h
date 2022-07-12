#ifndef TASK_24_03_22_ASM_TASKS_H
#define TASK_24_03_22_ASM_TASKS_H

void Algorithm4() {
    int n = 7;
    int *input_array = new int[]{1, 2, 2, 3, 2, 5, 5};
    int _size = 0;
    int output_array[40];
    int i = 0;
    int j = 1;
    for (i; i < n; ++i) {
        int count = 0;
        j = 1;
        for (j; j < _size + 1; ++j) {
            if (input_array[i] == output_array[j]) {
                ++count;
            }
        }
        if (count == 0) {
            output_array[_size + 1] = input_array[i];
            ++_size;
        }
    }
    output_array[0] = _size + 1;//new real length
    for (j = 0; j < _size + 1; ++j) {
        std::cout << output_array[j] << " " << std::endl;
    }
}

void Algorithm5(){
    //int *first_array = new int[]{2, 7, 1, 3, 2, 5, 5};
    //int *second_array = new int[]{2, -1, 1, 10, 0};
    int first_array[]{2, 7, 1, 3, 2, 5, 5};//уточнить с сайзом
    int second_array[]{2, -1, 1, 10, 0};
    int size_first = std::size(first_array);
    int size_second=std::size(second_array);
    const int merge_size=size_first+size_second;
    int merge_array[12];
    std::sort(first_array, first_array+size_first);
    std::sort(second_array, second_array+size_second);
    std::merge(first_array, first_array+7,second_array, second_array+5,  merge_array );

    for(int i=0; i< 12; ++i){

        std::cout<< merge_array[i]<< " ";
    }
}

#endif //TASK_24_03_22_ASM_TASKS_H
