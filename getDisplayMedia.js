'use strict';

import { Platform, NativeModules } from 'react-native';

import MediaStream from './MediaStream';
import MediaStreamError from './MediaStreamError';

const { CustomWebRTCModule } = NativeModules;

export default function getDisplayMedia(constraints) {
    if (!constraints || !constraints.video) {
        return Promise.reject(new TypeError());
    }

    return new Promise((resolve, reject) => {
        CustomWebRTCModule.getDisplayMedia()
            .then(data => {
                const { streamId, track } = data;

                const info = {
                    streamId: streamId,
                    streamReactTag: streamId,
                    tracks: [track]
                };

                const stream = new MediaStream(info);

                resolve(stream);
            }, error => {
                reject(new MediaStreamError(error));
            });
    });
}
