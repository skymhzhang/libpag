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

#include "LayerFilter.h"

namespace pag {
class BulgeFilter : public LayerFilter {
 public:
  explicit BulgeFilter(Effect* effect);
  ~BulgeFilter() override = default;

 protected:
  std::string onBuildVertexShader() override;

  std::string onBuildFragmentShader() override;

  void onPrepareProgram(const GLInterface* gl, unsigned program) override;

  void onUpdateParams(const GLInterface* gl, const Rect& contentBounds,
                      const Point& filterScale) override;

  std::vector<Point> computeVertices(const Rect& contentBounds, const Rect& transformedBounds,
                                     const Point& filterScale) override;

 private:
  Effect* effect = nullptr;

  int horizontalRadiusHandle = -1;
  int verticalRadiusHandle = -1;
  int bulgeCenterHandle = -1;
  int bulgeHeightHandle = -1;
  int pinningHandle = -1;
};
}  // namespace pag
