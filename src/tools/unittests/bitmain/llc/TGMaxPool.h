#ifndef ONNX_BM_TGMAXPOOL_H
#define ONNX_BM_TGMAXPOOL_H

#include "onnx/common/ir.h"
#include "TGOperator.h"

class TGMaxPool : public TGOperator {
public:
  TGMaxPool(const onnx::Node &node, uint64_t offset);
  virtual void emit(void) const;
private:
  uint64_t m_inputAddr;
  uint64_t m_outputAddr;
  int m_N;
  int m_C;
  int m_H;
  int m_W;
  int m_kH;
  int m_kW;
  int m_padH;
  int m_padW;
  int m_strideH;
  int m_strideW;
};


#endif
