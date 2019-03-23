/******************************************************************************
 * Copyright 2019 The Apollo Authors. All Rights Reserved.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *****************************************************************************/

/**
 * @file
 **/

#include "modules/planning/common/open_space_info.h"

namespace apollo {
namespace planning {
  void RecordDebug(apollo::planning_internal::Debug* ptr_debug) {
    // record trajectory information into debug ptr
    auto* ptr_partitioned_trajectories = ptr_debug->mutable_planning_data()
        ->mutable_open_space()->mutable_partitioned_trajectories();

    for (auto iter : paritioned_trajectories_) {
      auto picked_trajectory = iter.first;
      auto* ptr_added_trajectory =
          ptr_partitioned_trajectories->add_trajectory();
      for () {
        
      }


    }

    ////////////////////////////
    auto* smoothed_trajectory = open_space_debug_.mutable_smoothed_trajectory();
    for (size_t i = 0; i < horizon; ++i) {
      auto* smoothed_point = smoothed_trajectory->add_vehicle_motion_point();
      smoothed_point->mutable_trajectory_point()->mutable_path_point()->set_x(
        state_result_ds(0, i));
    smoothed_point->mutable_trajectory_point()->mutable_path_point()->set_y(
        state_result_ds(1, i));
    smoothed_point->mutable_trajectory_point()->mutable_path_point()->set_theta(
        state_result_ds(2, i));
    smoothed_point->mutable_trajectory_point()->set_v(state_result_ds(3, i));
    smoothed_point->set_steer(control_result_ds(0, i));
    smoothed_point->mutable_trajectory_point()->set_a(control_result_ds(1, i));
    relative_time += time_result_ds(0, i);
    smoothed_point->mutable_trajectory_point()->set_relative_time(
        relative_time);
  }
  auto* smoothed_point = smoothed_trajectory->add_vehicle_motion_point();
  smoothed_point->mutable_trajectory_point()->mutable_path_point()->set_x(
      state_result_ds(0, horizon));
  smoothed_point->mutable_trajectory_point()->mutable_path_point()->set_y(
      state_result_ds(1, horizon));
  smoothed_point->mutable_trajectory_point()->mutable_path_point()->set_theta(
      state_result_ds(2, horizon));
  smoothed_point->mutable_trajectory_point()->set_v(
      state_result_ds(3, horizon));
  relative_time += time_result_ds(0, horizon);
  smoothed_point->mutable_trajectory_point()->set_relative_time(relative_time);



  }
}  // namespace planning
}  // namespace apollo
