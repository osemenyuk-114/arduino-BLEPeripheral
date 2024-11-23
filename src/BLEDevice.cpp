// Copyright (c) Sandeep Mistry. All rights reserved.
// Licensed under the MIT license. See LICENSE file in the project root for full license information.

#include "Arduino.h"

#include "BLEDevice.h"

#define DEFAULT_ADVERTISING_INTERVAL 100
#define DEFAULT_CONNECTABLE          true

BLEDevice::BLEDevice() :
  _advertisingInterval(DEFAULT_ADVERTISING_INTERVAL),
  _minimumConnectionInterval(0),
  _maximumConnectionInterval(0),
  _connectable(DEFAULT_CONNECTABLE),
  _bondStore(NULL),
  _eventListener(NULL),

  _PPCP_minimumConnectionInterval(0),
  _PPCP_maximumConnectionInterval(0),
  _PPCP_slaveLatency(0),
  _PPCP_connectionSupervisionTimeout(0)

{
}

BLEDevice::~BLEDevice() {
}

void BLEDevice::setEventListener(BLEDeviceEventListener* eventListener) {
  this->_eventListener = eventListener;
}

void BLEDevice::setAdvertisingInterval(unsigned short advertisingInterval) {
  this->_advertisingInterval = advertisingInterval;
}

void BLEDevice::setConnectionInterval(unsigned short minimumConnectionInterval, unsigned short maximumConnectionInterval) {
  if (maximumConnectionInterval < minimumConnectionInterval) {
    maximumConnectionInterval = minimumConnectionInterval;
  }

  this->_minimumConnectionInterval = minimumConnectionInterval;
  this->_maximumConnectionInterval = maximumConnectionInterval;
}

void BLEDevice::setConnectable(bool connectable) {
  this->_connectable = connectable;
}

void BLEDevice::setBondStore(BLEBondStore& bondStore) {
  this->_bondStore = &bondStore;
}

void BLEDevice::setPPCP(unsigned short minimumConnectionInterval, unsigned short maximumConnectionInterval, unsigned short slaveLatency, unsigned short connectionSupervisionTimeout) {
  this->_PPCP_minimumConnectionInterval = minimumConnectionInterval;
  this->_PPCP_maximumConnectionInterval = maximumConnectionInterval;
  this->_PPCP_slaveLatency = slaveLatency;
  this->_PPCP_connectionSupervisionTimeout = connectionSupervisionTimeout;
}
