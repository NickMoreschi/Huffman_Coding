#include "PQueue.h"
using namespace std;

template< typename T, int MAX_SIZE >
PQueue<T, MAX_SIZE>::PQueue(){
  _size = 0;
}

template< typename T, int MAX_SIZE >
PQueue<T, MAX_SIZE>::PQueue(T* items, int size){
  _size = size;
  for (int i = 0; i < size; i++){
    _array[i+1] = items[i];
  }
  buildHeap();
}

template< typename T, int MAX_SIZE >
void PQueue<T, MAX_SIZE>::moveUp(){
  int _index = _size;
  while(_array[_index] < _array[_index/2]){
    if (_index == 1){
      return;
    }else{
    T temp = _array[_index/2];
    _array[_index/2] = _array[_index];
    _array[_index] = temp;
    _index = _index/2;
  }
  }
}

template< typename T, int MAX_SIZE >
void PQueue<T, MAX_SIZE>::insert(T item){
  _size = _size + 1;
  _array[_size] = item;
  moveUp();
}

template< typename T, int MAX_SIZE >
T PQueue<T, MAX_SIZE>::findMin(){
  return _array[1];
}

template< typename T, int MAX_SIZE >
void PQueue<T, MAX_SIZE>::deleteMin(){
  _array[1] = _array[_size];
  _size--;
  moveDown(1);
}

template< typename T, int MAX_SIZE >
bool PQueue<T, MAX_SIZE>::isEmpty(){
  if(_size == 0){
    return true;
  }else{
    return false;
  }
}

template< typename T, int MAX_SIZE >
int PQueue<T, MAX_SIZE>::size(){
  return _size;
}

template< typename T, int MAX_SIZE >
void PQueue<T, MAX_SIZE>::buildHeap(){
  for (int i = _size/2; i >=1; i --)
  {
    moveDown(i);
  }
}

template< typename T, int MAX_SIZE >
void PQueue<T, MAX_SIZE>::moveDown(int index){


  while (index * 2 <=_size){

    if (index*2+1 <= _size)
    {

      if (_array[index] > _array[index*2] || _array[index] > _array[index*2+1])
      {
        if (_array[index*2] <= _array[index*2+1])
        {
          T temp = _array[index];
          _array[index] = _array[index*2];
          _array[index*2] = temp;
          index = index * 2;
        }
        else
        {
          T temp = _array[index];
          _array[index] = _array[index*2+1];
          _array[index*2+1] = temp;
          index = index*2+1;
        }
      }
      else
      {
        index = index*2;
        return;
      }
    }
    else if(_array[index] > _array[index*2])
    {
        T temp = _array[index];
        _array[index] = _array[index*2];
        _array[index*2] = temp;
        index = index * 2;
    }else{
      index = index*2;
      return;
    }

    }

  }