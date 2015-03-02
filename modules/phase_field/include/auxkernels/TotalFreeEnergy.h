#ifndef TOTALFREEENERGY_H
#define TOTALFREEENERGY_H

#include "TotalFreeEnergyBase.h"

//Forward Declarations
class TotalFreeEnergy;

template<>
InputParameters validParams<TotalFreeEnergy>();

/**
 * Total free energy (both the bulk and gradient parts), where the bulk free energy has been defined in a material and called f_name
 */
class TotalFreeEnergy : public TotalFreeEnergyBase
{
public:
  TotalFreeEnergy(const std::string & name, InputParameters parameters);

protected:
  virtual Real computeValue();

  /// Bulk free energy material property
  MaterialProperty<Real> & _F;

  /// Gradient interface free energy coefficients
  std::vector<const MaterialProperty<Real> *> _kappas;
};

#endif //TOTALFREEENERGY_H
