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

#ifndef rtkDrawCylinderImageFilter_hxx
#define rtkDrawCylinderImageFilter_hxx


namespace rtk
{

template <class TInputImage, class TOutputImage>
void
DrawCylinderImageFilter<TInputImage, TOutputImage>::BeforeThreadedGenerateData()
{
  if (this->GetAxis()[0] * this->GetAxis()[1] * this->GetAxis()[2] != itk::NumericTraits<ScalarType>::ZeroValue())
  {
    itkExceptionMacro(<< "Axis " << this->GetAxis() << " does not contain any 0 value as a cylinder should.");
  }
  Superclass::BeforeThreadedGenerateData();
}

} // end namespace rtk

#endif
