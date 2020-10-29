#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <iostream>
#include <fstream>

using namespace std;

vector<int> vector_random;
vector<int> vector_reversed;
vector<int> vector_sorted;

/*  Implement a Heap class here (from the slides)  */
void swap(int &a, int &b){
    int temp=a;
    a=b;
    b=temp;
}

void swapforvec(vector<int> &a, int x, int y){
    int temp = a.at(x);
    a.at(x)=a.at(y);
    a.at(y)=temp;
}


class Heap {
private:
    //int data[MAXSIZE];//can change that to dynamic
    vector<int> *data = new vector<int>();
    int last;//last index
public:
    Heap(){last=-1;};  // constructor, consider data[i]=0 an empty slot
    ~Heap() { };//destructor
    void InsertHeap( int newthing, int &counter);
    int DeleteRoot(int &counter);
    void PrintHeap();
};

void Heap::PrintHeap(){//print in array order
    //  printf("HEAP: \n");
    for(int i=0; i<last;i++){
        printf("%d ", data->at(i));
    }
    printf("\n");

}

void Heap::InsertHeap( int newthing, int &counter){
    //printf("Inserting %d \n",newthing);
    //if (last>=(data->size()-1)) {printf("Heap is full\n");exit(0);}
    //add ot the end of the array
    //data[last+1]=newthing;
    data->push_back(newthing);
    //data->at(last-1)=newthing;
    last=data->size();
    if (last==1) return;//only one item in Heap
    //fix the heap before leaving
    //check parent of last
    int child_index=last-1;
    int par_index=0;
    bool swapping=true;
    while (swapping==true ){
        swapping=false;
        if(child_index%2==0) {
            par_index=child_index/2-1; //is a right child
        }
        else {
            par_index=child_index/2; //is a left child
        }
        if(par_index>=0){//make sure par_index is within the array
            counter = counter + 1;
            if (data->at(child_index) > data->at(par_index)) {
                swapforvec(*data, child_index, par_index);
                swapping = true;
                child_index = par_index;
            }
        }
    }
}

int Heap::DeleteRoot(int &counter){
    if(last<=0) {printf("Heap is already empty\n"); return false;}
    int a=0;
    int valuetodelete = data->at(0);
    /*for(int a=0;a<last;a++){
        if (data->at(a)==valuetodelete) break;
    }*/
    //printf("Index to delete is %d for item %d \n",a,valuetodelete);
    //swap node with last, "delete" last
    //data[a]=data[last];
    data->at(a)=data->at(last-1);
    //data[last]=0;//deleting...
    data->at(last-1)=0;
    data->erase(data->begin() + last-1);
    // subtract last
    last=last-1;
    //now fix the heap
    int parindex=0;
    int leftindex=parindex*2+1;//left child
    int rightindex=parindex*2+2;//right child
    bool swapping=true;
    if(last==2){
        counter = counter + 1;
        if(data->at(parindex)<data->at(leftindex)){
            swapforvec(*data,parindex,leftindex);
            return valuetodelete;
        } else {
            return valuetodelete;
        }

    } else if(last==1){
        return valuetodelete;
    } else if(last==0){
        return valuetodelete;
    }
    counter = counter + 1;
    while ( (data->at(parindex)<data->at(leftindex)||data->at(parindex)<data->at(rightindex)) && swapping==true){
        swapping=false;
        counter = counter + 1;
        if (data->at(rightindex)<data->at(leftindex)){//follow left
            //printf("Swap data[%d]=%d with data[%d]=%d \n",leftindex, data->at(leftindex), parindex, data->at(parindex));
            swapforvec(*data,leftindex,parindex);
            parindex=leftindex;
            swapping=true;
        }
        else{//else follow right
            //printf("Swap data[%d]=%d with data[%d]=%d \n",rightindex, data->at(rightindex), parindex, data->at(parindex));
            swapforvec(*data, rightindex,parindex);
            parindex=rightindex;
            swapping=true;
        }
        leftindex=parindex*2+1;
        rightindex=parindex*2+2;
        if(leftindex>last-1) break;
        else{
            if(rightindex>last-1){
                counter = counter + 1;
                if (data->at(parindex)<data->at(leftindex)) swapforvec(*data, parindex, leftindex);
                break;
            }
        }
        counter = counter + 1;
    }

    /*for(a=0;a<last;a++){
        if (data->at(a)==0){
            data->erase(data->begin()+a);
            last = data->size();
            break;
        }
    }*/
    return valuetodelete;
}


/* this is a possible prototype for the heapsort function */
/* the char* filename is just for printing the name, the file is opened and dealt with in the main() */
void heapsort(vector<int> &sortingvector,int number_of_elements, char* filename){
    int arr[5];
    cout<<"Heap before sorting: "<<filename<<endl;
    /* Heap myHeap; .//declare a Heap instance here */
    Heap *heap = new Heap();
    int inserts =0;
    int deletes =0;
    /* Using the sortingvector, INSERT elements into the Heap */
    for (int x:sortingvector){
        heap->InsertHeap(x, inserts);
    }

    /* After building the heap from the file, PRINT the current state of the heap before sorting */
    heap->PrintHeap();
    cout<<"InsertHeap: "<<inserts<< " comparisons";
    /* STORE how many comparisons were made until this point */

    /* DELETE elements from the Heap, copying it back to the vector in a way that it is sorted */
    for (int i = number_of_elements-1; i >= 0; i--) {
        sortingvector[i] = heap->DeleteRoot(deletes);
    }
    heap->PrintHeap();
    cout<<"DeleteRoot: "<<deletes<< " comparisons\n";
    cout<<"Vector after sorting:\n";
    for (int j = 0; j < number_of_elements; j++) {
        cout<<sortingvector[j]<<" ";
    }
    cout<<endl;

    /* STORE how many comparisons were made for the deletion process */

    /* PRINT the number of comparisons for the Insert and Deletion tasks */

    /* Print the state of the vector after sorting */

}




int main( int argc, char** argv ){//get filename from arguments
    char expression[100];
    int number;
    ifstream input_file_random;
    ifstream input_file_reversed;
    ifstream input_file_sorted;
    if(argc==4) {
        input_file_random.open(argv[1]);
        input_file_reversed.open(argv[2]);
        input_file_sorted.open(argv[3]);
    }
    else {printf("The program needs 3 filenames, in this order: random, reversed and sorted.\n");exit(0);}
    int number_of_elements_random=0;
    while(input_file_random >> number){
        sscanf(expression,"%d",&number);
        /*Comment out this printout, this is just to check that the file can be read */
//		printf("%d ",number );	
        vector_random.push_back(number);
        number_of_elements_random++;
    }
    /*Comment out this printout, this is just to check that the array was copied */
    /*printf("File %s:\n", argv[1]);
    for(int count=0;count<number_of_elements_random;count++){
        printf("%d ",vector_random[count]);
    }
    printf("\n");
    //end printout*/

    int number_of_elements_reversed=0;
    while(input_file_reversed >> number){
        sscanf(expression,"%d",&number);
        /*Comment out this printout, this is just to check that the file can be read */
//		printf("%d ",number );	
        vector_reversed.push_back(number);
        number_of_elements_reversed++;
    }
    /*Comment out this printout, this is just to check that the array was copied */
    /*printf("File %s:\n", argv[2]);
    for(int count=0;count<number_of_elements_reversed;count++){
        printf("%d ",vector_reversed[count]);
    }
    printf("\n");
    //end printout*/


    int number_of_elements_sorted=0;
    while(input_file_sorted >> number){
        sscanf(expression,"%d",&number);
        /*Comment out this printout, this is just to check that the file can be read */
//		printf("%d ",number );	
        vector_sorted.push_back(number);
        number_of_elements_sorted++;
    }
    /*Comment out this printout, this is just to check that the array was copied */
    /*printf("File %s:\n", argv[3]);
    for(int count=0;count<number_of_elements_sorted;count++){
        printf("%d ",vector_sorted[count]);
    }
    printf("\n");
    //end printout*/


    /* Implement or call your Heap sort here, the Heap class with methods should be copied/implemented before main() */
    heapsort(vector_random, number_of_elements_random, argv[1]);
    cout << endl;
    heapsort(vector_reversed, number_of_elements_reversed, argv[2]);
    cout << endl;
    heapsort(vector_sorted, number_of_elements_sorted, argv[3]);

}
