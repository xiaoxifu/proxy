/* Copyright 2019 Istio Authors. All Rights Reserved.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *    http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include "envoy/api/v2/core/grpc_service.pb.h"
#include "extensions/common/context.h"
#include "google/api/monitored_resource.pb.h"
#include "grpcpp/grpcpp.h"

namespace Extensions {
namespace Stackdriver {
namespace Common {

// Gets monitored resource proto based on the type and node metadata info.
// Only two types of monitored resource could be returned: k8s_container or
// k8s_pod.
void getMonitoredResource(const std::string &monitored_resource_type,
                          const ::wasm::common::NodeInfo &local_node_info,
                          google::api::MonitoredResource *monitored_resource);

// Set secure exchange service gRPC call credential.
void setSTSCallCredentialOptions(
    ::envoy::api::v2::core::GrpcService_GoogleGrpc_CallCredentials_StsService
        *sts_service,
    const std::string &sts_port);
void setSTSCallCredentialOptions(
    ::grpc::experimental::StsCredentialsOptions *sts_options,
    const std::string &sts_port);

}  // namespace Common
}  // namespace Stackdriver
}  // namespace Extensions
