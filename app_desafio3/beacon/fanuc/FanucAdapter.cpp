/*
 * Copyright Copyright 2012, System Insights, Inc.
 *
 *    Licensed under the Apache License, Version 2.0 (the "License");
 *    you may not use this file except in compliance with the License.
 *    You may obtain a copy of the License at
 *
 *       http://www.apache.org/licenses/LICENSE-2.0
 *
 *    Unless required by applicable law or agreed to in writing, software
 *    distributed under the License is distributed on an "AS IS" BASIS,
 *    WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *    See the License for the specific language governing permissions and
 *    limitations under the License.
 */

#include "internal.hpp"
#include "fanuc_adapter.hpp"
#include "server.hpp"
#include "string_buffer.hpp"

int main(int aArgc, const char *aArgv[]) {
    FanucAdapter *adapter = new FanucAdapter(7878);
    return adapter->main(aArgc, aArgv);
}
