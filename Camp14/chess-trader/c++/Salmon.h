#ifndef __Salmon_H__
#define __Salmon_H__

#include <CStrategy.h>

////////////////////////////////////////////////////////////
// Example C++ strategy that estimates the probability that
// white will win as a function of the sum of remaining
// pieces, weighted by how powerful they are. Like all C++
// strategies, this is a subclass of CStrategy and
// implements onExchangeMessage() and onChessMessage().
////////////////////////////////////////////////////////////

class Salmon : public CStrategy
{
public:
  Salmon();
  virtual ~Salmon();

  ////////////////////////////////////////////////////////// 
  // All CStrategy subclass must implement these methods.
  ////////////////////////////////////////////////////////// 
  void onExchangeMessage(const CExchangeMessage& em);
  void onChessMessage(const CChessMessage& cm);

private:
  void cancelAllOrders();
  unsigned computeFairPrice() const;
  int getScore(char piece) const;
  unsigned getPrice(int score) const;

  const unsigned maxPosition_;
  const unsigned maxOrderQuantity_;
};

#endif
