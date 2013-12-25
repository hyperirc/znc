/*
 * Copyright (C) 2004-2013 ZNC, see the NOTICE file for details.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */
 
INCLUDES
 
CGroup::CGroup(const CString& sGroupName)
		: m_sGroupName(sGroupName)
{
	m_bAllowAddNetwork = true;
	m_bAllowDelNetwork = true;
}

CGroup::~CGroup() {
}

template<class T>
struct TOption {
	const char *name;
	void (CUser::*pSetter)(T);
};

bool CGroup::ParseConfig(CConfig* pConfig, CString& sError) {
	TOption<bool> BoolOptions[] = {
		{ "allowaddnetwork", &CGroup::SetAllowAddNetwork },
		{ "allowdelnetwork", &CGroup::SetAllowDelNetwork },
	};
	size_t numBoolOptions = sizeof(BoolOptions) / sizeof(BoolOptions[0]);

	for (size_t i = 0; i < numBoolOptions; i++) {
		CString sValue;
		if (pConfig->FindStringEntry(BoolOptions[i].name, sValue))
			(this->*BoolOptions[i].pSetter)(sValue.ToBool());
	}

	return true;
}

CConfig CGroup::ToConfig() {
	CConfig config;

	config.AddKeyValuePair("AllowAddNetwork", CString(AllowAddNetwork()));
	config.AddKeyValuePair("AllowDelNetwork", CString(AllowDelNetwork()));

	return config;
}

// Setters
void CGroup::SetAllowAddNetwork(bool b) { m_bAllowAddNetwork = b; }
void CGroup::SetAllowDelNetwork(bool b) { m_bAllowDelNetwork = b; }
// !Setters

// Getters
bool CGroup::AllowAddNetwork() const { return m_bAllowAddNetwork; }
bool CGroup::AllowDelNetwork() const { return m_bAllowDelNetwork; }
// !Getters