import {NativeModules, NativeEventEmitter} from 'react-native';

const { CustomWebRTCModule } = NativeModules;

const EventEmitter = new NativeEventEmitter(CustomWebRTCModule);

export default EventEmitter;
