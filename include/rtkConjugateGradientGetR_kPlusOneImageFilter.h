/*=========================================================================
 *
 *  Copyright RTK Consortium
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

#ifndef rtkConjugateGradientGetR_kPlusOneImageFilter_h
#define rtkConjugateGradientGetR_kPlusOneImageFilter_h

#include <itkImageToImageFilter.h>
#include <itkVectorImage.h>
#include <itkBarrier.h>

#include "rtkConfiguration.h"
#include "rtkMacro.h"

namespace rtk
{
/** \class ConjugateGradientGetR_kPlusOneImageFilter
 *
 * \author Cyril Mory
 *
 * \ingroup RTK
 */
template< typename TInputImage>
class ConjugateGradientGetR_kPlusOneImageFilter : public itk::ImageToImageFilter< TInputImage, TInputImage>
{
public:
    /** Standard class type alias. */
    using Self = ConjugateGradientGetR_kPlusOneImageFilter;
    using Superclass = itk::ImageToImageFilter< TInputImage, TInputImage>;
    using Pointer = itk::SmartPointer< Self >;
    using OutputImageRegionType = typename TInputImage::RegionType;

    /** Method for creation through the object factory. */
    itkNewMacro(Self)

    /** Run-time type information (and related methods). */
    itkTypeMacro(ConjugateGradientGetR_kPlusOneImageFilter, itk::ImageToImageFilter)

    /** Functions to set the inputs */
    void SetRk(const TInputImage* Rk);
    void SetPk(const TInputImage* Pk);
    void SetAPk(const TInputImage* APk);

    itkGetMacro(Alphak, double)
    itkGetMacro(SquaredNormR_k, double)
    itkGetMacro(SquaredNormR_kPlusOne, double)

protected:
    ConjugateGradientGetR_kPlusOneImageFilter();
    virtual ~ConjugateGradientGetR_kPlusOneImageFilter() override {}

    typename TInputImage::Pointer GetRk();
    typename TInputImage::Pointer GetPk();
    typename TInputImage::Pointer GetAPk();

    /** Initialize the thread synchronization barrier before the threads run,
        and create a few vectors in which each thread will store temporary
        accumulation results */
    void BeforeThreadedGenerateData() override;

    /** Do the real work */
    void ThreadedGenerateData(const typename TInputImage::RegionType &
                               outputRegionForThread,
                               ThreadIdType threadId) override;

    /**  Set m_alphak to its correct value as it has to be passed to other filters */
    void AfterThreadedGenerateData() override;

private:
    ConjugateGradientGetR_kPlusOneImageFilter(const Self &); //purposely not implemented
    void operator=(const Self &);  //purposely not implemented
    double m_Alphak;
    double m_SquaredNormR_k;
    double m_SquaredNormR_kPlusOne;

    // Thread synchronization tool
    itk::Barrier::Pointer m_Barrier;

    // These vector store one accumulation value per thread
    // The values are then sumed
    std::vector<double> m_SquaredNormR_kVector;
    std::vector<double> m_SquaredNormR_kPlusOneVector;
    std::vector<double> m_PktApkVector;

};

template<>
void
ConjugateGradientGetR_kPlusOneImageFilter<itk::VectorImage<double, 3>>
::ThreadedGenerateData(const itk::VectorImage<double, 3>::RegionType &
                           outputRegionForThread,
                           ThreadIdType threadId);

} //namespace RTK


#ifndef ITK_MANUAL_INSTANTIATION
#include "rtkConjugateGradientGetR_kPlusOneImageFilter.hxx"
#endif

#endif
