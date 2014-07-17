/*=========================================================================
*
*  Copyright Insight Software Consortium
*
*  Licensed under the Apache License, Version 2.0 (the "License");
*  you may not use this file except in compliance with the License.
*  You may obtain a copy of the License at
*
*         http://www.apache.org/licenses/LICENSE-2.0.txt
*
*  Unless required by applicable law or agreed to in writing, software
*  distributed under the License is distributed on an "AS IS" BASIS,
*  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
*  See the License for the specific language governing permissions and
*  limitations under the License.
*
*=========================================================================*/
#ifndef __srtkAdditionalProcedures_h
#define __srtkAdditionalProcedures_h


#include "srtkBasicFilters.h"
#include "srtkImage.h"
#include "srtkTransform.h"
#include "srtkInterpolator.h"
#include "srtkPatchBasedDenoisingImageFilter.h"

namespace rtk {
namespace simple {


/**
 * \brief rtk::simple::ResampleImageFilter Procedural Interface
 *
 * These functions call the execute method of ResampleImageFilter
 * in order to support a procedual API.
 *
 * There three very by how the output image's domain parameters are
 * specified. The first method used the input image, the second uses
 * a reference image, while the last procedure has them manually
 * specified.
 *
 * \sa rtk::simple::ResampleImageFilter for the object oriented interface
* @{
 */
SRTKBasicFilters_EXPORT Image Resample ( const Image& image1,
                                         Transform transform = rtk::simple::Transform(),
                                         InterpolatorEnum interpolator = rtk::simple::srtkLinear,
                                         double defaultPixelValue = 0.0,
                                         PixelIDValueEnum outputPixelType = srtkUnknown );

SRTKBasicFilters_EXPORT Image Resample ( const Image& image1,
                                         const Image& referenceImage,
                                         Transform transform = rtk::simple::Transform(),
                                         InterpolatorEnum interpolator = rtk::simple::srtkLinear,
                                         double defaultPixelValue = 0.0,
                                         PixelIDValueEnum outputPixelType = srtkUnknown );

SRTKBasicFilters_EXPORT Image Resample ( const Image& image1,
                                         std::vector<uint32_t> size,
                                         Transform transform = rtk::simple::Transform(),
                                         InterpolatorEnum interpolator = rtk::simple::srtkLinear,
                                         std::vector<double> outputOrigin = std::vector<double>(3, 0.0),
                                         std::vector<double> outputSpacing = std::vector<double>(3, 1.0),
                                         std::vector<double> outputDirection = std::vector<double>(),
                                         double defaultPixelValue = 0.0,
                                         PixelIDValueEnum outputPixelType = srtkUnknown );
    /**@}*/



/**
 * \brief rtk::simple::PatchBasedDenoisingImageFilter Procedural Interface
 *
 * This function directly calls the execute method of PatchBasedDenoisingImageFilter
 * in order to support a procedural API
 *
 * \sa rtk::simple::PatchBasedDenoisingImageFilter for the object oriented interface
 */
SRTKBasicFilters_EXPORT Image PatchBasedDenoising (const Image& image1,
                                                   rtk::simple::PatchBasedDenoisingImageFilter::NoiseModelType noiseModel,
                                                   double kernelBandwidthSigma = 400.0,
                                                   uint32_t patchRadius = 4u,
                                                   uint32_t numberOfIterations = 1u,
                                                   uint32_t numberOfSamplePatches = 200u,
                                                   double sampleVariance = 400.0,
                                                   double noiseSigma = 0.0,
                                                   double noiseModelFidelityWeight = 0.0 );

// Disable for certain wrapped languages due to overload shadowing
#if !defined(SWIGLUA)

SRTKBasicFilters_EXPORT Image PatchBasedDenoising (const Image& image1,
                                                   double kernelBandwidthSigma = 400.0,
                                                   uint32_t patchRadius = 4u,
                                                   uint32_t numberOfIterations = 1u,
                                                   uint32_t numberOfSamplePatches = 200u,
                                                   double sampleVariance = 400.0);
#endif


}
}
#endif
