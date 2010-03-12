// Copyright (c) 2009, Object Computing, Inc.
// All rights reserved.
// See the file license.txt for licensing information.
#include <Common/QuickFASTPch.h>
#include "FieldIdentity.h"

#ifdef _MSC_VER
#pragma warning(disable:4355) // disable warning C4355: 'this' : used in base member initializer list
#endif
using namespace QuickFAST;
using namespace Messages;

static
std::string anonName(void * address)
{
  return boost::lexical_cast<std::string>(address);
}

FieldIdentity::FieldIdentity()
  : localName_(anonName(this))
  , refcount_(0)
{
  qualifyName();
}

FieldIdentity::~FieldIdentity()
{
}

void
FieldIdentity::freeFieldIdentity()const
{
  delete this;
}

