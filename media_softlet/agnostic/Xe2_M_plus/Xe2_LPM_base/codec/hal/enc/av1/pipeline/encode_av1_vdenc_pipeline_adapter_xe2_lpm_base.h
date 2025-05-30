/*
* Copyright (c) 2021-2024, Intel Corporation
*
* Permission is hereby granted, free of charge, to any person obtaining a
* copy of this software and associated documentation files (the "Software"),
* to deal in the Software without restriction, including without limitation
* the rights to use, copy, modify, merge, publish, distribute, sublicense,
* and/or sell copies of the Software, and to permit persons to whom the
* Software is furnished to do so, subject to the following conditions:
*
* The above copyright notice and this permission notice shall be included
* in all copies or substantial portions of the Software.
*
* THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS
* OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
* FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL
* THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR
* OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE,
* ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR
* OTHER DEALINGS IN THE SOFTWARE.
*/
//!
//! \file     encode_av1_vdenc_pipeline_adapter_xe2_lpm_base.h
//! \brief    Defines the interface to adapt to av1 vdenc encode pipeline Xe2_LPM+
//!

#ifndef __ENCODE_AV1_VDENC_PIPELINE_ADAPTER_XE2_LPM_BASE_H__
#define __ENCODE_AV1_VDENC_PIPELINE_ADAPTER_XE2_LPM_BASE_H__

#include "encode_pipeline_adapter.h"
#include "encode_av1_vdenc_pipeline_xe2_lpm_base.h"

class EncodeAv1VdencPipelineAdapterXe2_Lpm_Base : public EncoderPipelineAdapter
{
public:
    EncodeAv1VdencPipelineAdapterXe2_Lpm_Base(
        CodechalHwInterfaceNext *   hwInterface,
        CodechalDebugInterface *debugInterface);

    virtual MOS_STATUS Allocate(CodechalSetting *codecHalSettings);

    virtual MOS_STATUS Execute(void *params);

    virtual MOS_STATUS GetStatusReport(void *status, uint16_t numStatus);
    
    virtual MOS_STATUS ResolveMetaData(PMOS_RESOURCE pInput, PMOS_RESOURCE pOutput) override;

    virtual void Destroy();

protected:
    std::shared_ptr<encode::Av1VdencPipelineXe2_Lpm_Base> m_encoder = nullptr;

MEDIA_CLASS_DEFINE_END(EncodeAv1VdencPipelineAdapterXe2_Lpm_Base)
};
#endif  // !__ENCODE_AV1_VDENC_PIPELINE_ADAPTER_XE2_LPM_BASE_H__
