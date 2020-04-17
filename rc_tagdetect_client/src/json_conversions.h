/*
 * Copyright (c) 2020 Roboception GmbH
 *
 * Author: Elena Gambaro
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * 1. Redistributions of source code must retain the above copyright notice,
 * this list of conditions and the following disclaimer.
 *
 * 2. Redistributions in binary form must reproduce the above copyright notice,
 * this list of conditions and the following disclaimer in the documentation
 * and/or other materials provided with the distribution.
 *
 * 3. Neither the name of the copyright holder nor the names of its contributors
 * may be used to endorse or promote products derived from this software without
 * specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE
 * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 */

#ifndef RC_TAGDETECT_JSON_CONVERSIONS_H
#define RC_TAGDETECT_JSON_CONVERSIONS_H

#include "json_conversions_common.h"

#include <rc_tagdetect_client/Tag.h>
#include <rc_tagdetect_client/DetectedTags.h>

#include <rc_tagdetect_client/DetectTags.h>
#include <rc_tagdetect_client/StartContinuousDetection.h>

namespace rc_tagdetect_client
{

inline void to_json(nlohmann::json& j, const Tag& p)
{
  j["id"] = p.id;
  j["size"] = p.size;
}

inline void from_json(const nlohmann::json& j, Tag& p)
{
  j.at("id").get_to(p.id);
  j.at("size").get_to(p.size);
}

inline void from_json(const nlohmann::json& j, DetectedTag& p)
{
  j.at("timestamp").get_to(p.header.stamp);
  j.at("pose_frame").get_to(p.header.frame_id);
  j.at("tag").get_to(p.tag);
  j.at("instance_id").get_to(p.instance_id);
  j.at("pose").get_to(p.pose.pose);
  p.pose.header.stamp = p.header.stamp;
  p.pose.header.frame_id = p.header.frame_id;
}

inline void to_json(nlohmann::json& j, const DetectTagsRequest& p)
{
  j["tags"] = p.tags;
}

inline void from_json(const nlohmann::json& j, DetectTagsResponse& p)
{
  j.at("tags").get_to(p.tags);
  j.at("timestamp").get_to(p.timestamp);
  j.at("return_code").get_to(p.return_code);
}

}  // namespace rc_tagdetect_client

#endif  // RC_TAGDETECT_JSON_CONVERSIONS_H
