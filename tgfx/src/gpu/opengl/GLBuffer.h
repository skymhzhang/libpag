/////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Tencent is pleased to support the open source community by making libpag available.
//
//  Copyright (C) 2021 THL A29 Limited, a Tencent company. All rights reserved.
//
//  Licensed under the Apache License, Version 2.0 (the "License"); you may not use this file
//  except in compliance with the License. You may obtain a copy of the License at
//
//      http://www.apache.org/licenses/LICENSE-2.0
//
//  unless required by applicable law or agreed to in writing, software distributed under the
//  license is distributed on an "as is" basis, without warranties or conditions of any kind,
//  either express or implied. see the license for the specific language governing permissions
//  and limitations under the license.
//
/////////////////////////////////////////////////////////////////////////////////////////////////

#pragma once

#include "gpu/Resource.h"

namespace pag {
class GLBuffer : public Resource {
 public:
  static std::shared_ptr<GLBuffer> Make(Context* context, const uint16_t* buffer, size_t length);

  unsigned bufferID() const {
    return _bufferID;
  }

  size_t length() const {
    return _length;
  }

 protected:
  void computeRecycleKey(BytesKey*) const override;

 private:
  void onRelease(Context* context) override;

  const void* uniqueKey = nullptr;
  size_t _length = 0;
  unsigned _bufferID = 0;
};
}  // namespace pag
