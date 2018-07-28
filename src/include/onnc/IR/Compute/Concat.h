//===- Concat.h --------------------------------------------------===//
//
//                             The ONNC Project
//
// See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//
#ifndef ONNC_IR_COMPUTE_OPERATOR_CONCAT_H
#define ONNC_IR_COMPUTE_OPERATOR_CONCAT_H
#include <onnc/IR/ComputeOperator.h>
#include <onnc/IR/ComputeVisitor.h>
#include <onnc/IR/Compute/Attributes.h>
#include <onnc/Support/IOStream.h>

namespace onnc {

class Concat : public ComputeOperator
{
public:
  enum IOConst {
    kInputs = 0,
    kConcatResult = 0
  };

  static char ID;

public:
  Concat(const IntAttr& pAxis);

  ~Concat() { }

  const IntAttr& getAxis() const { return m_Axis; }

  Tensor* getInput(unsigned int pIdx) override { return static_cast<Tensor*>(m_Inputs[pIdx]); }

  const Tensor* getInput(unsigned int pIdx) const override { return static_cast<Tensor*>(m_Inputs[pIdx]); }

  Tensor* getOutput(unsigned int pIdx) override { return static_cast<Tensor*>(m_Outputs[pIdx]); }

  const Tensor* getOutput(unsigned int pIdx) const override { return static_cast<Tensor*>(m_Outputs[pIdx]); }

  Tensor* getInputs(size_t pIdx) { return getInput(kInputs + pIdx); }

  Tensor* getConcatResult() { return getOutput(kConcatResult); }

  void addInput(Tensor& pTensor) { m_Inputs.push_back(&pTensor); }

  bool isInputEmpty() const { return m_Inputs.empty(); }

  unsigned int getInputSize() const { return m_Inputs.size(); }

  void setInputs(size_t pIdx, Tensor& pTensor) { m_Inputs[kInputs + pIdx] = &pTensor; }

  void setConcatResult(Tensor& pTensor) { m_Outputs[kConcatResult] = &pTensor; }

  void print(std::ostream& pOS) const override;

  void accept(ComputeVisitor& pVisitor) override { pVisitor.visit(*this); }

  void accept(ComputeVisitor& pVisitor) const override { pVisitor.visit(*this); }

  static bool classof(const ComputeOperator* pOp);

private:
  IntAttr m_Axis;
};

} // namespace of onnc

#endif
