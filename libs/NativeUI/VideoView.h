/* Copyright 2013 David Axmark

Licensed under the Apache License, Version 2.0 (the "License");
you may not use this file except in compliance with the License.
You may obtain a copy of the License at

	http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License.
*/

/*! \addtogroup NativeUILib
 *  @{
 */

/**
 *  @defgroup NativeUILib Native UI Library
 *  @{
 */

/**
 * @file VideoView.h
 * @author Bogdan Iusco
 *
 * \brief An instance of VideoView is used for managing the playback of a movie
 * from a file or a network stream.
 * For video view events see VideoViewListener.
 * Note: This widget is not available on Windows Phone 7.
 */

#ifndef NATIVEUI_VIDEO_VIEW_H_
#define NATIVEUI_VIDEO_VIEW_H_

#include "Widget.h"

namespace NativeUI
{

    // Forward declaration.
    class VideoViewListener;

    /**
     * \brief An instance of VideoView is used for managing the playback of a
     * movie from a file or a network stream.
     *
     * For video view events see VideoViewListener.
	 * Note: This widget is not available on Windows Phone 7.
     */
    class VideoView : public Widget
    {
    public:
        /**
         * Constructor.
         */
        VideoView();

        /**
         * Destructor.
         */
        virtual ~VideoView();

        /**
         * Set the video path.
         * Note: available only for Android.
         * @param path A valid path to a video file.
         * @return Any of the following result codes:
         * - #MAW_RES_OK if the property could be set.
         * - #MAW_RES_INVALID_PROPERTY_VALUE if the path value was invalid.
         */
        virtual int setPath(const MAUtil::String& path);

        /**
         * Set the video url.
         * @param url A valid url to a video file.
         * @return Any of the following result codes:
         * - #MAW_RES_OK if the property could be set.
         * - #MAW_RES_INVALID_PROPERTY_VALUE if the url value was invalid.
         */
        virtual int setURL(const MAUtil::String& url);

        /**
         * Play the video.
         * A valid path or url must be set before calling this method.
         */
        virtual void play();

        /**
         * Pause the video.
         */
        virtual void pause();

        /**
         * Stop the video.
         */
        virtual void stop();

        /**
         * Get the video duration.
         * On Android: this value is known only after
         *     MAW_VIDEO_WIDGET_STATE_SOURCE_READY event is received.
         * On iOS: this value can be retrieved after
         *     MAW_VIDEO_STATE_PLAYING event is received.
         * @return The video's duration in milliseconds.
         */
        virtual int getDuration();

        /**
         * Seek into the video.
         * @param time Valid time in milliseconds.
         * @return Any of the following result codes:
         * - #MAW_RES_OK if the property could be set.
         * - #MAW_RES_INVALID_PROPERTY_VALUE if the time value was invalid.
         */
        virtual int seekTo(const int time);

        /**
         * Get the buffer percentage of the played video file.
         * Only for Android platform.
         * @return The buffer percentage of the played video file.
         */
        virtual int getBufferPercentage();

        /**
         * Get the current video time.
         * @return The current video time.
         */
        virtual int currentPlaybackTime();

        /**
         * Show video control.
         * Platform: iOS.
         */
        void showControl();

        /**
         * Hide video control.
         * Platform: iOS.
         */
        void hideControl();

        /**
         * Check if the video control is visible.
         * Platform: iOS.
         * @return true if the video control is visible, false otherwise.
         */
        bool isControlVisible();

        /**
         * Add an video view event listener.
         * @param listener The listener that will receive video view events.
         */
        virtual void addVideoViewListener(VideoViewListener* listener);

        /**
         * Remove the video view listener.
         * @param listener The listener that receives video view events.
         */
        virtual void removeVideoViewListener(VideoViewListener* listener);

    protected:
        /**
         * This method is called when there is an event for this widget.
         * It passes on the event to all widget's listeners.
         * @param widgetEventData The data for the widget event.
         */
        virtual void handleWidgetEvent(MAWidgetEventData* widgetEventData);

    private:
        /**
         * Array with video view listeners.
         */
        MAUtil::Vector<VideoViewListener*> mVideoViewListeners;
    };

} // namespace NativeUI

#endif /* NATIVEUI_VIDEO_VIEW_H_ */

/*! @} */
