/****************************************************************/
/* MOOSE - Multiphysics Object Oriented Simulation Environment  */
/*                                                              */
/*          All contents are licensed under LGPL V2.1           */
/*             See LICENSE for full restrictions                */
/****************************************************************/
#ifndef COMPUTEEIGENSTRAINBASE_H
#define COMPUTEEIGENSTRAINBASE_H

#include "Material.h"

class RankTwoTensor;

/**
 * ComputeEigenstrainBase is the base class for eigenstrain tensors
 */
class ComputeEigenstrainBase : public Material
{
public:
  ComputeEigenstrainBase(const InputParameters & parameters);

protected:
  virtual void initQpStatefulProperties();
  virtual void computeQpProperties();

  ///Compute the eigenstrain and store in _eigenstrain
  virtual void computeQpEigenstrain() = 0;

  ///Base name prepended to material property name
  std::string _base_name;

  ///Material property name for the eigenstrain tensor
  std::string _eigenstrain_name;

  ///Whether the eigenstrain model should compute the total or incremental eigenstrain
  bool _incremental_form;

  ///Stores the current total eigenstrain
  MaterialProperty<RankTwoTensor> & _eigenstrain;

  ///Stores the total eigenstrain in the previous step (only for incremental form)
  const MaterialProperty<RankTwoTensor> * _eigenstrain_old;

  /**
   * Helper function for models that compute the eigenstrain based on a volumetric
   * strain.  This function computes the diagonal components of the eigenstrain tensor.
   * param volumetric_strain The current volumetric strain to be applied
   */
  Real computeVolumetricStrainComponent(const Real volumetric_strain) const;

  /// Restartable data to check for the zeroth and first time steps for thermal calculations
  bool & _step_zero;
};

#endif // COMPUTEEIGENSTRAINBASE_H
