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
class MotionBlurFilter : public LayerFilter {
 public:
  static void TransformBounds(Rect* bounds, const Point& filterScale, Layer* layer,
                              Frame layerFrame);

  MotionBlurFilter();
  ~MotionBlurFilter() override = default;

  bool updateLayer(Layer* layer, Frame layerFrame);

 protected:
  std::string onBuildVertexShader() override;

  std::string onBuildFragmentShader() override;

  void onPrepareProgram(const GLInterface* gl, unsigned program) override;

  void onUpdateParams(const GLInterface* gl, const Rect& contentBounds,
                      const Point& filterScale) override;

  std::vector<Point> computeVertices(const Rect& contentBounds, const Rect& transformedBounds,
                                     const Point& filterScale) override;

 private:
  Matrix previousMatrix = Matrix::I();
  Matrix currentMatrix = Matrix::I();

  int prevTransformHandle = 0;
  int transformHandle = 0;
  int velCenterHandle = 0;
  int maxDistanceHandle = 0;
};
}  // namespace pag
