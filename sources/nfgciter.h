//#
//# FILE: contiter.h -- Normal form contingency iterator class
//#
//# $Id$
//#

#ifndef CONTITER_H
#define CONTITER_H

#include "gblock.h"
#include "gvector.h"

template <class T> class NormalForm;
class StrategyProfile;

//
// This class is useful for iterating around the normal form.  This iterator
// allows the user choose to hold some players' strategies constant while
// iterating over the other players' strategies.  This is useful, for example,
// in displaying a 2D window into the n-D space of strategy profiles as in
// the normal form display code.  The constructor takes the normal form to
// work on and a gBlock<int> containing the numbers of players the user wants
// to hold constant.  The iteration is based on an index that goes from 1 to
// the total number of possible contingencies in increments of 1.
//
template <class T> class ContIter    {
  private:
    NormalForm<T> *N;
    StrategyProfile *profile;
    gBlock<int> frozen, thawed;

  public:
    ContIter(NormalForm<T> &);
    ContIter(NormalForm<T> *);
    ~ContIter();

    void First(void);

    void Freeze(const gBlock<int> &);
    void Freeze(int);
    void Thaw(int);

// These next two only work on frozen strategies
    void Set(int pl, int num);
    int Next(int pl);

    int NextContingency(void);

    long GetIndex(void) const;

    const T &Evaluate(int pl) const;
    T &Evaluate(int pl);
    void Evaluate(gVector<T> &);

    void Dump(void) const;
};

#endif   // CONTITER_H




