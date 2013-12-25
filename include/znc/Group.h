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

#ifndef _GROUP_H
#define _GROUP_H

INCLUDES

class CGroup {
public:
	CGroup(const CString& sGroupName);
	~CGroup();

	bool ParseConfig(CConfig* Config, CString& sError);

	CConfig ToConfig();

	// Setters
	void SetAllowAddNetwork(bool b);
	void SetAllowDelNetwork(bool b);
	// !Setters

	// Getters
	bool AllowAddNetwork() const;
	bool AllowDelNetwork() const;
	// !Getters

protected:
	const CString         m_sGroupName;

	bool                  m_bAllowAddNetwork;
	bool                  m_bAllowDelNetwork;
};

#endif // !_GROUP_H
