#ifndef HEAP_H
#define HEAP_H
#include <functional>
#include <stdexcept>
#include <vector>

template <typename T, typename PComparator = std::less<T> >
class Heap 
{
public:
  /**
   * @brief Construct a new Heap object
   * 
   * @param m ary-ness of heap tree (default to 2)
   * @param c binary predicate function/functor that takes two items
   *          as an argument and returns a bool if the first argument has
   *          priority over the second.
   */
  Heap(int m=2, PComparator c = PComparator());

  /**
  * @brief Destroy the Heap object
  * 
  */
  ~Heap();

  /**
   * @brief Push an item to the heap
   * 
   * @param item item to heap
   */
  void push(const T& item);

  /**
   * @brief Returns the top (priority) item
   * 
   * @return T const& top priority item
   * @throw std::underflow_error if the heap is empty
   */
  T const & top() const;

  /**
   * @brief Remove the top priority item
   * 
   * @throw std::underflow_error if the heap is empty
   */
  void pop();

  /// returns true if the heap is empty

  /**
   * @brief Returns true if the heap is empty
   * 
   */
  bool empty() const;

    /**
   * @brief Returns size of the heap
   * 
   */
  size_t size() const;

private:
  /// Add whatever helper functions and data members you need below
	std::vector<T> heap_;
	int mary;
	PComparator comp;




};

// Add implementation of member functions here


// We will start top() for you to handle the case of 
// calling top on an empty heap
template <typename T, typename PComparator>
Heap<T,PComparator>::Heap(int m, PComparator c){
	mary = m;
	comp = c; 
}

template <typename T, typename PComparator>
Heap<T, PComparator>::~Heap()
{
}

// We will start pop() for you to handle the case of 
// calling top on an empty heap
template <typename T, typename PComparator>
void Heap<T,PComparator>::pop()
{
  if(empty()){
		throw std::underflow_error("Heap is empty");
  }
	std::swap(heap_[0], heap_.back());
  heap_.pop_back();

	int loc = 0;
	int child = 1;
  while(child < heap_.size()){
    int max_child = child;
    for(int i = 2; i <= mary; i++){
      if(child + i - 1 < heap_.size() && comp(heap_[child + i - 1], heap_[max_child])){
        max_child = child + i - 1;
      }
    }
    if(comp(heap_[loc], heap_[max_child])){
      break;
    }

    std::swap(heap_[loc], heap_[max_child]);

    // Move down the heap
    loc = max_child;
    child = mary * loc + 1;
  }




}

template <typename T, typename PComparator>
void Heap<T,PComparator>::push(const T& item)
{
	heap_.push_back(item);
	int loc = heap_.size()-1;
	int parent = (loc-1)/mary;
	while(parent >= 0 && comp(heap_[loc],heap_[parent])){
		std::swap(heap_[parent], heap_[loc]);
		loc = parent;
		parent = (loc-1)/mary;
	}
	
}

template <typename T, typename PComparator>
bool Heap<T,PComparator>::empty() const
{
  return heap_.size() == 0;
}

template <typename T, typename PComparator>
size_t Heap<T,PComparator>::size() const
{
  return heap_.size();
}

template <typename T, typename PComparator>
T const & Heap<T,PComparator>::top() const
{
  if(empty()){
     throw std::underflow_error("Heap is empty!");
  }
  return heap_[0];
}




#endif

