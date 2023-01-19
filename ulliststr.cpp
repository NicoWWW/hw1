#include <cstddef>
#include <stdexcept>
#include "ulliststr.h"

ULListStr::ULListStr()
{
  head_ = NULL;
  tail_ = NULL;
  size_ = 0;
}

ULListStr::~ULListStr()
{
  clear();
}

bool ULListStr::empty() const
{
  return size_ == 0;
}

size_t ULListStr::size() const
{
  return size_;
}

// WRITE YOUR CODE HERE

/**
   * Adds a new value to the back of the list
   *   - MUST RUN in O(1)
   */
  void ULListStr::push_back(const std::string& val){
    if(tail_==nullptr){
      tail_ = new Item();/*
      tail_->first = 0;
      tail_->last = 1;*/
      tail_->val[tail_->first] = val;
      tail_ -> last++;
      size_++;
      head_ = tail_;
    }
    else if (tail_->last < 10){
      tail_ -> val[tail_->last] = val;
      tail_->last ++;
      size_++;
    }
    else{
      Item* temp = new Item();
      temp->val[temp->first] = val;
      temp->last ++;
      size_++;
      temp->prev = tail_;
      temp->next = nullptr;
      tail_->next = temp;
      tail_ = temp;
    }
  }

  /**
   * Removes a value from the back of the list
   *   - MUST RUN in O(1)
   */
  void ULListStr::pop_back(){
    if(tail_==nullptr){
      return;
    }
    else{
      tail_->last--;
      size_--;
    }
    if (tail_->first == tail_->last){
      if (head_==tail_){
        delete head_;
        tail_ = nullptr;
        head_ = nullptr;
      }
      else{
        Item* temp = tail_;
        tail_ = tail_->prev;
        tail_->next = nullptr;
        delete temp;
      }
    }
  }
  
  /**
   * Adds a new value to the front of the list.
   * If there is room before the 'first' value in
   * the head node add it there, otherwise, 
   * allocate a new head node.
   *   - MUST RUN in O(1)
   */
  void ULListStr::push_front(const std::string& val){
    if(head_==nullptr){
      head_ = new Item();
      head_->first = 9;
      head_->last = 10;
      head_->val[head_->first] = val;
      size_++;
      tail_ = head_;
    }
    else if (head_->first > 0){
      head_ -> val[head_->first-1] = val;
      head_->first --;
      size_++;
    }
    else{
      Item* temp = new Item();
      temp->first = 9;
      temp->last = 10;
      temp->val[temp->first] = val;
      size_++;
      temp->next = head_;
      temp->prev = nullptr;
      head_->prev = temp;
      head_ = temp;
    }
  }

  /**
   * Removes a value from the front of the list
   *   - MUST RUN in O(1)
   */
  void ULListStr::pop_front(){
    if(head_==nullptr){
      return;
    }
    else{
      head_->first++;
      size_--;
    }
    if (head_->first == head_->last){
      if (head_==tail_){
        delete tail_;
        tail_ = nullptr;
        head_ = nullptr;
      }
      else{
        Item* temp = head_;
        head_ = head_->next;
        head_->prev = nullptr;
        delete temp;
      }
    }
  }
  
  /**
   * Returns a const reference to the back element
   *   - MUST RUN in O(1)
   */
  std::string const & ULListStr::back() const{
    if (tail_==nullptr){
      return "Nothing found. Empty List.";
    }
    return tail_->val[tail_->last-1];
  }

  /**
   * Returns a const reference to the front element
   *   - MUST RUN in O(1)
   */
  std::string const & ULListStr::front() const{
    if (head_==nullptr){
      return "Nothing found. Empty List.";
    }
    return head_->val[head_->first];
  }
  
  /** 
   * Returns a pointer to the item at index, loc,
   *  if loc is valid and NULL otherwise
   *   - MUST RUN in O(n) 
   */
  std::string* ULListStr::getValAtLoc(size_t loc) const{
    if (loc>size_){
      return NULL;
    }
    Item* temp = head_;
    size_t curr = loc;
    while(temp->last - temp->first <=curr){
      curr -= (temp->last - temp->first);
      temp = temp->next;
    }
    return &temp->val[temp->first+curr];
  }

void ULListStr::set(size_t loc, const std::string& val)
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  *ptr = val;
}

std::string& ULListStr::get(size_t loc)
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  return *ptr;
}

std::string const & ULListStr::get(size_t loc) const
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  return *ptr;
}

void ULListStr::clear()
{
  while(head_ != NULL){
    Item *temp = head_->next;
    delete head_;
    head_ = temp;
  }
  tail_ = NULL;
  size_ = 0;
}
