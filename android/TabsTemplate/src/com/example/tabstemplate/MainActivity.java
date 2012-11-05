/************************************************************************************************************/
/*                                                                                            Date : 09/2012*/
/*                                   PRESENTATION                                                           */
/*                     Copyright (c) 2012 JRD Communications, Inc.                                          */
/************************************************************************************************************/
/*                                                                                                          */
/*           This material is company confidential, cannot be reproduced in any                             */
/*           form without the written permission of JRD Communications, Inc.                                */
/*                                                                                                          */
/*==========================================================================================================*/
/*   Author :                                                                                               */
/*   Role :                                                                                                 */
/*   Reference documents :                                                                                  */
/*==========================================================================================================*/
/* Comments :                                                                                               */
/*     file    :..\packages\apps\Music\src\com\android\music\MusicBrowserActivity.java                      */
/*     Labels  :                                                                                            */
/*==========================================================================================================*/
/* Modifications   (month/day/year)                                                                         */
/*==========================================================================================================*/
/* date      | author       |FeatureID                 |modification                                        */
/*=============|================|==============================|============================================*/
/*2012-09-29 |yanchao.chen  |FR330058-yanchao.chen-001 |implement SRS and Porting SDMID                     */
/*=============|================|==============================|=============================================*/
/*2012-09-29 |yanchao.chen  |FR330462-yanchao.chen-002 |[Ergo]: SRS                                         */
/*10/16/12 | yongjie.xiao |FR316989-yongjie.xiao-002|[Ergo]: music player(GD)                               */
/*==========================================================================================================*/
/* Problems Report(PR/CR)                                                                                   */
/*==========================================================================================================*/
/* date     | author      | PR #                |                                                           */
/*===========|================|========================|====================================================*/
/* Copyright Statement:
 *
 * This software/firmware and related documentation ("MediaTek Software") are
 * protected under relevant copyright laws. The information contained herein
 * is confidential and proprietary to MediaTek Inc. and/or its licensors.
 * Without the prior written permission of MediaTek inc. and/or its licensors,
 * any reproduction, modification, use or disclosure of MediaTek Software,
 * and information contained herein, in whole or in part, shall be strictly prohibited.
 */
/* MediaTek Inc. (C) 2010. All rights reserved.
 *
 * BY OPENING THIS FILE, RECEIVER HEREBY UNEQUIVOCALLY ACKNOWLEDGES AND AGREES
 * THAT THE SOFTWARE/FIRMWARE AND ITS DOCUMENTATIONS ("MEDIATEK SOFTWARE")
 * RECEIVED FROM MEDIATEK AND/OR ITS REPRESENTATIVES ARE PROVIDED TO RECEIVER ON
 * AN "AS-IS" BASIS ONLY. MEDIATEK EXPRESSLY DISCLAIMS ANY AND ALL WARRANTIES,
 * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE OR NONINFRINGEMENT.
 * NEITHER DOES MEDIATEK PROVIDE ANY WARRANTY WHATSOEVER WITH RESPECT TO THE
 * SOFTWARE OF ANY THIRD PARTY WHICH MAY BE USED BY, INCORPORATED IN, OR
 * SUPPLIED WITH THE MEDIATEK SOFTWARE, AND RECEIVER AGREES TO LOOK ONLY TO SUCH
 * THIRD PARTY FOR ANY WARRANTY CLAIM RELATING THERETO. RECEIVER EXPRESSLY ACKNOWLEDGES
 * THAT IT IS RECEIVER'S SOLE RESPONSIBILITY TO OBTAIN FROM ANY THIRD PARTY ALL PROPER LICENSES
 * CONTAINED IN MEDIATEK SOFTWARE. MEDIATEK SHALL ALSO NOT BE RESPONSIBLE FOR ANY MEDIATEK
 * SOFTWARE RELEASES MADE TO RECEIVER'S SPECIFICATION OR TO CONFORM TO A PARTICULAR
 * STANDARD OR OPEN FORUM. RECEIVER'S SOLE AND EXCLUSIVE REMEDY AND MEDIATEK'S ENTIRE AND
 * CUMULATIVE LIABILITY WITH RESPECT TO THE MEDIATEK SOFTWARE RELEASED HEREUNDER WILL BE,
 * AT MEDIATEK'S OPTION, TO REVISE OR REPLACE THE MEDIATEK SOFTWARE AT ISSUE,
 * OR REFUND ANY SOFTWARE LICENSE FEES OR SERVICE CHARGE PAID BY RECEIVER TO
 * MEDIATEK FOR SUCH MEDIATEK SOFTWARE AT ISSUE.
 *
 * The following software/firmware and/or related documentation ("MediaTek Software")
 * have been modified by MediaTek Inc. All revisions are subject to any receiver's
 * applicable license agreements with MediaTek Inc.
 */

/*
 * Copyright (C) 2007 The Android Open Source Project
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

package com.example.tabstemplate;

import android.annotation.SuppressLint;
import android.app.LocalActivityManager;
import android.app.TabActivity;
import android.content.BroadcastReceiver;
import android.content.Context;
import android.content.Intent;
import android.content.IntentFilter;
import android.content.res.Configuration;
import android.graphics.drawable.Drawable;
import android.media.AudioManager;
import android.os.Bundle;
import android.support.v4.view.PagerAdapter;
import android.support.v4.view.ViewPager;
import android.util.Log;
import android.view.MenuItem;
import android.view.View;
import android.widget.PopupMenu;
import android.widget.SearchView;
import android.widget.TabHost;
import android.widget.TabHost.OnTabChangeListener;
import android.widget.TabWidget;
import android.widget.TextView;

import java.util.ArrayList;
import java.util.HashMap;

@SuppressLint("NewApi")
public class MainActivity extends TabActivity implements OnTabChangeListener, ViewPager.OnPageChangeListener {
    private static final String TAG = "tabstemplate";

    private static final String TAB0 = "tab0";
    private static final String TAB1 = "tab1";
    private static final String TAB2 = "tab2";
    private static final String TAB3 = "tab3";
    private static final int TAB0_INDEX = 0;
    private static final int TAB1_INDEX = 1;
    private static final int TAB2_INDEX = 2;
    private static final int TAB3_INDEX = 3;
    private final static HashMap<String, Integer> TAB_MAP = new HashMap<String, Integer>(5);

    static {
        TAB_MAP.put(TAB0, TAB0_INDEX);
        TAB_MAP.put(TAB1, TAB1_INDEX);
        TAB_MAP.put(TAB2, TAB2_INDEX);
        TAB_MAP.put(TAB3, TAB3_INDEX);
    }

    private LocalActivityManager mActivityManager;
    private ViewPager mViewPager;
    private TabHost mTabHost;
    private ArrayList<View> mPagers = new ArrayList<View>();;
    private int mTabCount;
    private int mCurrentTab;

    @Override
    public void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        Log.d(TAG, "onCreate");
        setContentView(R.layout.main);
        
        mActivityManager = new LocalActivityManager(this, false);
        mActivityManager.dispatchCreate(savedInstanceState);

        mTabHost = getTabHost();
        initTab();
        mCurrentTab = TAB0_INDEX;
        Log.d(TAG, "onCreate mCurrentTab:" + mCurrentTab);
        mTabHost.setOnTabChangedListener(this);

        initPager();
        mViewPager = (ViewPager) findViewById(R.id.viewpage);
        mViewPager.setAdapter(new MusicPagerAdapter());
        mViewPager.setOnPageChangeListener(this);

    }

    @Override
    public void onResume() {
        super.onResume();
        Log.d(TAG, "onResume>>>");
        mTabHost.setCurrentTab(mCurrentTab);
        mActivityManager.dispatchResume();
        Log.d(TAG, "onResume<<<");
    }

    @Override
    public void onPause() {
        Log.d(TAG, "onPause");
        mActivityManager.dispatchPause(false);
        super.onPause();
    }

    @Override
    public void onStop() {
        mActivityManager.dispatchStop();
        super.onStop();
    }

    @Override
    public void onDestroy() {
        Log.d(TAG, "onDestroy");
        mActivityManager.dispatchDestroy(false);
        super.onDestroy();
    }

    /**
     * get current tab id though index
     * 
     * @param index
     * @return
     */
    private String getStringId(int index) {
        String tabStr = TAB0;
        switch (index) {
            case TAB1_INDEX:
                tabStr = TAB1;
                break;
            case TAB2_INDEX:
                tabStr = TAB2;
                break;
            case TAB3_INDEX:
                tabStr = TAB3;
                break;
            case TAB0_INDEX:
            default:
                Log.d(TAG, "ARTIST_INDEX or default");
                break;
        }
        return tabStr;
    }

    /**
     * initial tab host
     */
    @SuppressLint("NewApi")
    private void initTab() {
        Log.d(TAG, "initTab>>");
        final TabWidget tabWidget = (TabWidget) getLayoutInflater().inflate(R.layout.buttonbar, null);
        mTabCount = tabWidget.getChildCount();
        View tabView;
        for (int i = 0; i < mTabCount; i++) {
            tabView = tabWidget.getChildAt(0);
            if (tabView != null) {
                tabWidget.removeView(tabView);
            }
            Log.d(TAG, "addTab:" + i);
            mTabHost.addTab(mTabHost.newTabSpec(getStringId(i)).setIndicator(tabView)
                    .setContent(android.R.id.tabcontent));
        }
        Log.d(TAG, "initTab<<");
    }

    /**
     * get current view
     * 
     * @param index
     * @return View
     */
    private View getView(int index) {
        Log.d(TAG, "getView>>>index = " + index);
        View view = null;
        Intent intent = new Intent();
        switch (index) {
            case TAB0_INDEX:
                intent.setClass(this, Activity0.class);
                break;
            case TAB1_INDEX:
                intent.setClass(this, Activity1.class);
                break;
            case TAB2_INDEX:
                intent.setClass(this, Activity2.class);
                break;
            case TAB3_INDEX:
                intent.setClass(this, Activity3.class);
                break;
            default:
                Log.d(TAG, "default");
                return null;
        }
        intent.addFlags(Intent.FLAG_ACTIVITY_CLEAR_TOP);
        view = mActivityManager.startActivity(getStringId(index), intent).getDecorView();
        Log.d(TAG, "getView<<<");
        return view;
    }

    /**
     * initial view pager
     */
    private void initPager() {
        mPagers.clear();
        View view = null;
        for (int i = 0; i <= TAB3_INDEX; i++) {
            view = (i == mCurrentTab) ? getView(i) : null;
            mPagers.add(view);
        }
    }

    /**
     * OnTabChangeListener for TabHost
     * 
     * @param tabId
     */
    public void onTabChanged(String tabId) {
        int tabIndex = TAB_MAP.get(tabId);
        Log.d(TAG, "onTabChanged-tabId:" + tabId);
        // Log.d(TAG, "onTabChanged-tabIndex:" + tabIndex);
        if ((tabIndex >= TAB0_INDEX) && (tabIndex <= TAB3_INDEX)) {
            mViewPager.setCurrentItem(tabIndex);
            mCurrentTab = tabIndex;
        }
    }

    /**
     * OnPageChangeListener for ViewPager
     * 
     * @param position
     */
    public void onPageSelected(int position) {
        Log.d(TAG, "onPageSelected-position:" + position);
        mTabHost.setCurrentTab(position);
    }

    /**
     * onPageScrolled
     * 
     * @param position
     * @param positionOffset
     * @param positionOffsetPixels
     */
    public void onPageScrolled(int position, float positionOffset, int positionOffsetPixels) {
    }

    /**
     * onPageScrollStateChanged
     * 
     * @param state
     */
    public void onPageScrollStateChanged(int state) {
    }

    /**
     * MusicPagerAdapter for scroll page
     */
    private class MusicPagerAdapter extends PagerAdapter {
        @Override
        public void destroyItem(View container, int position, Object object) {
            ViewPager viewPager = ((ViewPager) container);
            Log.d(TAG, "destroyItem-position:" + position);
            viewPager.removeView(mPagers.get(position));
        }

        @Override
        public Object instantiateItem(View container, int position) {
            ViewPager viewPager = ((ViewPager) container);
            View view = mPagers.get(position);
            Log.d(TAG, "instantiateItem-position:" + position);
            if (view == null) {
                view = getView(position);
                mPagers.remove(position);
                mPagers.add(position, view);
                mActivityManager.dispatchResume();
            }
            viewPager.addView(view);
            return mPagers.get(position);
        }

        public int getCount() {
            // Log.d(TAG, "getCount:" + mPagers.size());
            return mPagers.size();
        }

        public boolean isViewFromObject(View view, Object object) {
            return view == object;
        }
    }

}
