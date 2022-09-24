/*
* Copyright (c) Facebook, Inc. and its affiliates.
*
* This source code is licensed under the MIT license found in the
* LICENSE file in the root directory of this source tree.
*/

#include "MockInstance.h"

#include <cxxreact/JsArgumentHelpers.h>

using namespace facebook::react;

using facebook::xplat::jsArgAsInt;
using std::vector;

MockInstance::MockInstance(std::shared_ptr<vector<int64_t>> sumCache)
: sumCache_{sumCache}
{
}

void MockInstance::initializeBridge(std::unique_ptr<InstanceCallback> callback,
                      std::shared_ptr<JSExecutorFactory> jsef,
                      std::shared_ptr<MessageQueueThread> jsQueue,
                      std::shared_ptr<ModuleRegistry> moduleRegistry)
{
}

void MockInstance::setSourceURL(std::string /*sourceURL*/)
{
}

void MockInstance::loadScriptFromString(std::unique_ptr<const JSBigString> string,
                          std::string sourceURL, bool loadSynchronously)
{
}

void MockInstance::setGlobalVariable(std::string propName,
                       std::unique_ptr<const JSBigString> jsonValue)
{
}

void *MockInstance::getJavaScriptContext()
{
  return nullptr;
}

bool MockInstance::isInspectable()
{
  return false;
}

bool MockInstance::isBatchActive()
{
  return false;
}

void MockInstance::callJSFunction(std::string &&module, std::string &&method,
                    folly::dynamic &&params)
{
  sumCache_->emplace_back(jsArgAsInt(params, 0));
}

void MockInstance::callJSCallback(uint64_t callbackId, folly::dynamic &&params)
{
}

// This method is experimental, and may be modified or removed.
void MockInstance::registerBundle(uint32_t bundleId, const std::string& bundlePath)
{
}

void MockInstance::handleMemoryPressure(int pressureLevel)
{
}
