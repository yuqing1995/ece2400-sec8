//========================================================================
// SListIObj.cc
//========================================================================
// Implementation for ListIObj

#include <cstdio>
#include <cassert>
#include "SListIObj.h"
#include "ece2400-stdlib.h"

//------------------------------------------------------------------------
// SListIObj Default Constructor
//------------------------------------------------------------------------

SListIObj::SListIObj()
{
  m_head_p = nullptr;
}

//------------------------------------------------------------------------
// SListIObj Destructor
//------------------------------------------------------------------------

SListIObj::~SListIObj()
{
  clear();
}

//------------------------------------------------------------------------
// SListIObj Copy Constructor
//------------------------------------------------------------------------

SListIObj::SListIObj( const SListIObj& lst )
{
  m_head_p = nullptr;
  copy(lst);
}

//------------------------------------------------------------------------
// SListIObj Overloaded Assignment Operator
//------------------------------------------------------------------------

SListIObj& SListIObj::operator=( const SListIObj& lst )
{
  clear();
  copy(lst);
  return *this;
}

//------------------------------------------------------------------------
// SListIObj::push_front
//------------------------------------------------------------------------

void SListIObj::push_front( const IObject& v )
{
  Node* new_node = new Node;
  new_node->obj_p = v.clone();
  new_node->next_p = m_head_p;
  m_head_p = new_node;
}

//------------------------------------------------------------------------
// SListIObj::at
//------------------------------------------------------------------------

const IObject& SListIObj::at( size_t idx ) const
{
  Node* tmp = m_head_p;
  while (tmp != nullptr){
    idx--;
    tmp = tmp->next_p;
    if (idx == 0){
      break;
    }
  }
  return *(tmp->obj_p);
}

//------------------------------------------------------------------------
// SListIObj::reverse
//------------------------------------------------------------------------

void SListIObj::reverse()
{
  Node* prev = nullptr;
  Node* next = nullptr;
  Node* curr = m_head_p;
  while(curr != nullptr){
    next = curr->next_p;
    curr->next_p = prev;
    prev = curr;
    curr = next;
  }
  m_head_p = prev;
}

//------------------------------------------------------------------------
// SListIObj::print
//------------------------------------------------------------------------

void SListIObj::print() const
{
  Node* tmp = m_head_p;
  while (tmp != nullptr){
    tmp->obj_p->print();
    tmp = tmp->next_p;
    printf("->");
  }
  printf("\n");
}

//------------------------------------------------------------------------
// SListIObj::copy
//------------------------------------------------------------------------

void SListIObj::copy( const SListIObj& lst )
{
  
}

//------------------------------------------------------------------------
// SListIObj::clear
//------------------------------------------------------------------------

void SListIObj::clear()
{
  while(m_head_p != nullptr){
    Node* temp = m_head_p->next_p;
    delete m_head_p->obj_p;
    delete m_head_p;
    m_head_p = temp;
  }
}

