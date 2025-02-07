#pragma once

#include "public.h"

#include <yt/yt/core/ytree/yson_struct.h>

namespace NYT::NGpu {

////////////////////////////////////////////////////////////////////////////////

DEFINE_ENUM(EGpuInfoSourceType,
    (NvGpuManager)
    (NvidiaSmi)
);

class TGpuInfoSourceConfig
    : public NYTree::TYsonStruct
{
public:
    //! Type of the GPU info source for use.
    EGpuInfoSourceType Type;

    // The following fields are used for NvManager info source only.
    TString NvGpuManagerServiceAddress;
    TString NvGpuManagerServiceName;
    std::optional<TString> NvGpuManagerDevicesCgroupPath;
    bool GpuIndexesFromNvidiaSmi;

    REGISTER_YSON_STRUCT(TGpuInfoSourceConfig);

    static void Register(TRegistrar registrar);
};

DEFINE_REFCOUNTED_TYPE(TGpuInfoSourceConfig)

////////////////////////////////////////////////////////////////////////////////

} // namespace NYT::NGpu
