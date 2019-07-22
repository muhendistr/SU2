/*!
 * \file CScalarVariable.hpp
 * \brief Class for defining the variables of scalar transport equations.
 * \author T. Economon
 * \version 6.2.0 "Falcon"
 *
 * The current SU2 release has been coordinated by the
 * SU2 International Developers Society <www.su2devsociety.org>
 * with selected contributions from the open-source community.
 *
 * The main research teams contributing to the current release are:
 *  - Prof. Juan J. Alonso's group at Stanford University.
 *  - Prof. Piero Colonna's group at Delft University of Technology.
 *  - Prof. Nicolas R. Gauger's group at Kaiserslautern University of Technology.
 *  - Prof. Alberto Guardone's group at Polytechnic University of Milan.
 *  - Prof. Rafael Palacios' group at Imperial College London.
 *  - Prof. Vincent Terrapon's group at the University of Liege.
 *  - Prof. Edwin van der Weide's group at the University of Twente.
 *  - Lab. of New Concepts in Aeronautics at Tech. Institute of Aeronautics.
 *
 * Copyright 2012-2019, Francisco D. Palacios, Thomas D. Economon,
 *                      Tim Albring, and the SU2 contributors.
 *
 * SU2 is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * SU2 is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with SU2. If not, see <http://www.gnu.org/licenses/>.
 */

#pragma once

#include "CVariable.hpp"

/*!
 * \class CScalarVariable
 * \brief Main class for defining the variables of scalar transport eqns.
 * \ingroup Scalar_Equations
 * \author T. Economon
 */
class CScalarVariable : public CVariable {
protected:
  su2double *Diffusivity;  /*!< \brief Vector of mass diffusivities for scalar transport. */
  
public:
  /*!
   * \brief Constructor of the class.
   */
  CScalarVariable(void);
  
  /*!
   * \overload
   * \param[in] val_scalar - Pointer to the scalar solution values.
   * \param[in] val_nDim   - Number of dimensions of the problem.
   * \param[in] val_nvar   - Number of variables of the problem.
   * \param[in] config     - Definition of the particular problem.
   */
  CScalarVariable(su2double      *val_scalar,
                  unsigned short val_nDim,
                  unsigned short val_nvar,
                  CConfig        *config);
  
  /*!
   * \brief Destructor of the class.
   */
  virtual ~CScalarVariable(void);
  
  /*!
   * \brief Set the value of the mass diffusivity
   * \param[in] val_diffusivity - the mass diffusivity.
   * \param[in] val_ivar        - eqn. index to the mass diffusivity.
   */
  inline void SetDiffusivity(su2double      val_diffusivity,
                             unsigned short val_ivar) {
    Diffusivity[val_ivar] = val_diffusivity;
  }
  
  /*!
   * \brief Get the value of the mass diffusivity
   * \param[in] val_ivar - eqn. index to the mass diffusivity.
   * \return Value of the mass diffusivity
   */
  inline su2double GetDiffusivity(unsigned short val_ivar) {
    return Diffusivity[val_ivar];
  }
  
  /*!
   * \brief Get the value of the mass diffusivities
   * \return Pointer to the mass diffusivities
   */
  inline su2double* GetDiffusivity(void) {
    return Diffusivity;
  }

};
