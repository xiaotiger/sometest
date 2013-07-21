#include <stdio.h>
#include <algorithm>

const int MAX_NUM = 1024;

class InPut {
    private:
        int* data_;
        bool have_;
        int curr_;
        int num_;
        int size_;
    public:
        InPut(int size):data_(NULL), have_(false), curr_(0), num_(0), size_(size) {
            data_ = (int*) malloc (size_ * sizeof(int));
            curr_ = 0;
        }
        ~InPut() {
            if (data_ != NULL) {
                free(data_);
            }
            have_ = false;
            curr_ = 0;
            size_ = 0;
        }
        bool have() { return have_; }
        int value() { return data_[curr_]; }
        int insert(int item) {
            if (have_ == false) { have_ = true; }
            if (num_ < size_) {
                data_[num_] = item;
                num_ ++;
            } else {
                printf("sorry no space\n");
                return -1;
            }
            return 0;
        }
        int sort() {
            std::sort(data_, data_ + num_);
        }
        int next() {
            if (curr_ >= num_ - 1) {
                have_ = false;
                return -1;
            } else {

                return data_[curr_ ++ ];
            }
        }
        void print() {
            for (int i = 0; i < num_; i ++) {
                printf("%d\t", data_[i]);
            }
            printf("\n");

        }
};


class OutPut {
    private :
        int* data_;
        int num_;
    public :
        OutPut() {
            data_ = (int*) malloc (MAX_NUM * sizeof(int));
            num_ = 0;
        }
        ~OutPut() {
            if (data_ != NULL) {
                free(data_);
                data_ = NULL;
            }
        }
        int operator()(int item) {
            if(num_ >= MAX_NUM) {
                printf("no space!\n");
                return -1;
            }
            data_[num_++] = item; 
            return 0;

        }

        int print() {
            for (int i = 0; i < num_; i ++) {
                printf("%d\t", data_[i]);
            }
            printf("\n");

        }

};

int merge(InPut **in, int in_num, OutPut &out) {
    int i = 0;
    int j = 0;
    int min;
    int count = 0;
    for (; i < in_num; ++ i) {
        if (in[i]->have()) {
            in[j++] = in[i];
        }
    }

    in_num = j;

    while (in_num > 0) {
        min = 0;
        for (i = 1; i < in_num; ++ i) {
            if (in[i]->value() < in[min]->value()){
                min = i;
            }
        }
        ++ count;
        if (out(in[min]->value())) {
            printf("out () error\n");
            return -1;
        }

        if (in[min]->next() == -1) {
            in_num --;
            for (i = min; i < in_num; ++ i) {
                in[i] = in[i+1];
            }
        }
    }

    return count;
}


int main() {
    InPut** g_in = (InPut**) malloc ( 3 * sizeof(InPut*));
    g_in[1] = new InPut(3);
    g_in[1]->insert(21);
    g_in[1]->insert(12);
    g_in[1]->insert(33);
    printf("input 1:\n");
    g_in[1]->print();
    g_in[1]->sort();
    g_in[1]->print();
    g_in[0] = new InPut(2);
    g_in[0]->insert(11);
    g_in[0]->insert(7);
    g_in[0]->insert(6);
    printf("input 0:\n");
    g_in[0]->print();
    g_in[0]->sort();
    g_in[0]->print();
    g_in[2] = new InPut(4);
    g_in[2]->insert(1);
    g_in[2]->insert(47);
    g_in[2]->insert(27);
    g_in[2]->insert(14);
    printf("input 2:\n");
    g_in[2]->print();
    g_in[2]->sort();
    g_in[2]->print();

    OutPut out;
    merge(g_in, 3, out);
    printf("out result:\n");
    out.print();
    return 0;
}
