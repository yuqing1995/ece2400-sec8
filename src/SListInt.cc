//========================================================================
// SListInt.cc
//========================================================================
// Implementation for ListInt

#include <cstdio>
#include <cassert>
#include "SListInt.h"

//------------------------------------------------------------------------
// SListInt Default Constructor
//------------------------------------------------------------------------

SListInt::SListInt()
{
  m_head_p = nullptr;
}

//------------------------------------------------------------------------
// SListInt Destructor
//------------------------------------------------------------------------

SListInt::~SListInt()
{
  clear();
}

//------------------------------------------------------------------------
// SListInt Copy Constructor
//------------------------------------------------------------------------

SListInt::SListInt( const SListInt& lst )
{
  m_head_p = nullptr;
  copy(lst);
}

//------------------------------------------------------------------------
// SListInt Overloaded Assignment Operator
//------------------------------------------------------------------------

SListInt& SListInt::operator=( const SListInt& lst )
{
  clear();
  copy(lst);
  return *this;
}

//------------------------------------------------------------------------
// SListInt::push_front
//------------------------------------------------------------------------

void SListInt::push_front( int v )
{
  Node* new_node_p   = new Node;
  new_node_p->value  = v;
  new_node_p->next_p = m_head_p;
  m_head_p           = new_node_p;
}

//------------------------------------------------------------------------
// SListInt::at
//------------------------------------------------------------------------

int SListInt::at( size_t idx ) const
{
  Node*  curr_p   = m_head_p;
  size_t curr_idx = 0;

  while ( curr_p != nullptr ) {
    if ( curr_idx == idx )
      return curr_p->value;
    curr_idx += 1;
    curr_p   = curr_p->next_p;
  }

  return 0;
}

//------------------------------------------------------------------------
// SListInt::reverse
//------------------------------------------------------------------------

void SListInt::reverse()
{
  size_t size   = 0;
  Node*  curr_p = m_head_p;
  while ( curr_p != nullptr ) {
    size   += 1;
    curr_p = curr_p->next_p;
  }

  int* tmp = new int[size];

  size_t i = 0;
  curr_p   = m_head_p;
  while ( curr_p != nullptr ) {
    tmp[i++] = curr_p->value;
    curr_p = curr_p->next_p;
  }

  size_t j = size-1;
  curr_p   = m_head_p;
  while ( curr_p != nullptr ) {
    curr_p->value = tmp[j--];
    curr_p = curr_p->next_p;
  }

  delete[] tmp;
}

//------------------------------------------------------------------------
// SListInt::print
//------------------------------------------------------------------------

void SListInt::print() const
{
  Node* curr_p = m_head_p;
  while ( curr_p != nullptr ) {
    std::printf( "%d ", curr_p->value );
    curr_p = curr_p->next_p;
  }
  std::printf( "\n" );
}

//------------------------------------------------------------------------
// SListInt::copy
//------------------------------------------------------------------------

void SListInt::copy( const SListInt& lst )
{
  Node* curr_p = lst.m_head_p;
  while ( curr_p != nullptr ) {
    push_front( curr_p->value );
    curr_p = curr_p->next_p;
  }
  reverse();
}

//------------------------------------------------------------------------
// SListInt::clear
//------------------------------------------------------------------------

void SListInt::clear()
{
  while ( m_head_p != nullptr ) {
    Node* temp_p = m_head_p->next_p;
    delete m_head_p;
    m_head_p = temp_p;
  }
}

